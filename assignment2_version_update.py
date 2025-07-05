import os
import re
from pathlib import Path

def update_file(file_path, pattern, new_text):
    if not file_path.exists():
        raise FileNotFoundError(f"Couldn't find: {file_path}")
    
    content = file_path.read_text()
    updated_content = re.sub(pattern, new_text, content)
    file_path.write_text(updated_content)
    print(f"Updated: {file_path.name}")

def main():
    build_num = os.environ.get("BuildNum")
    base_path = os.environ.get("SourcePath")

    if not build_num or not base_path:
        raise EnvironmentError("Both BuildNum and SourcePath must be set.")

    src_dir = Path(base_path) / "develop" / "global" / "src"

    update_file(
        src_dir / "SConstruct",
        r"point=\d+",
        f"point={build_num}"
    )

    update_file(
        src_dir / "VERSION",
        r"ADLMSDK_VERSION_POINT\s*=\s*\d+",
        f"ADLMSDK_VERSION_POINT= {build_num}"
    )

if __name__ == "__main__":
    main()
