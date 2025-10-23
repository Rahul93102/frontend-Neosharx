#!/usr/bin/env python
"""
Database Recovery Script for NeoSharX
This script helps recover from database corruption issues
"""

import os
import sys
import shutil
from datetime import datetime

def main():
    # Change to Backend flow directory
    backend_path = os.path.join(os.path.dirname(__file__), 'Backend flow')
    os.chdir(backend_path)
    sys.path.insert(0, backend_path)
    
    # Set Django settings
    os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'backend.settings')
    
    import django
    django.setup()
    
    from django.conf import settings
    
    db_path = settings.DATABASES['default']['NAME']
    
    print("=" * 60)
    print("NeoSharX Database Recovery Tool")
    print("=" * 60)
    print()
    
    if not os.path.exists(db_path):
        print(f"❌ Database file not found: {db_path}")
        print("   Creating new database...")
        create_new_database()
        return
    
    print(f"Database file: {db_path}")
    print(f"Size: {os.path.getsize(db_path)} bytes")
    print()
    
    # Check if database is corrupted
    try:
        import sqlite3
        conn = sqlite3.connect(db_path)
        cursor = conn.cursor()
        cursor.execute("SELECT name FROM sqlite_master WHERE type='table';")
        tables = cursor.fetchall()
        conn.close()
        
        print(f"✅ Database is healthy")
        print(f"   Found {len(tables)} tables")
        return
        
    except Exception as e:
        print(f"❌ Database is corrupted: {str(e)}")
        print()
        
        # Backup corrupted database
        backup_path = f"{db_path}.corrupted.{datetime.now().strftime('%Y%m%d_%H%M%S')}.bak"
        print(f"📦 Backing up corrupted database to: {backup_path}")
        shutil.copy2(db_path, backup_path)
        
        # Remove corrupted database
        print(f"🗑️  Removing corrupted database...")
        os.remove(db_path)
        
        # Create new database
        print(f"🔧 Creating new database...")
        create_new_database()


def create_new_database():
    """Create a fresh database"""
    from django.core.management import call_command
    
    print()
    print("Running migrations...")
    call_command('makemigrations')
    call_command('migrate')
    
    print()
    print("=" * 60)
    print("✅ Database recovery complete!")
    print("=" * 60)
    print()
    print("Next steps:")
    print("1. Create a superuser: python manage.py createsuperuser")
    print("2. Load any backup data if available")
    print("3. Restart the development server")
    print()


if __name__ == '__main__':
    main()
