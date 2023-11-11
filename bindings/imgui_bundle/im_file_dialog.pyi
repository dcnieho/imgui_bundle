"""ImFileDialog: based on https://github.com/dfranx/ImFileDialog
Thanks to dfranx (https://github.com/dfranx)
"""
# ruff: noqa: F821
from __future__ import annotations
from typing import List

from imgui_bundle.imgui import ImTextureID


class Path:
    def __init__(self, path: str) -> None:
        pass
    def path(self) -> str:
        pass
    def filename(self) -> str:
        pass
    def extension(self) -> str:
        pass
    def parent_path(self) -> str:
        pass

# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# <litgen_stub> // Autogenerated code below! Do not edit!
####################    <generated_from:ImFileDialog.h>    ####################
class FileDialog:
    @staticmethod
    def instance() -> FileDialog:
        pass
    def __init__(self) -> None:
        pass
    def save(self, key: str, title: str, filter: str, starting_dir: str = "") -> bool:
        pass
    def open(
        self,
        key: str,
        title: str,
        filter: str,
        is_multiselect: bool = False,
        starting_dir: str = "",
    ) -> bool:
        pass
    def is_done(self, key: str) -> bool:
        pass
    def has_result(self) -> bool:
        pass
    def get_result(self) -> Path:
        pass
    def get_results(self) -> List[Path]:
        pass
    def close(self) -> None:
        pass
    def remove_favorite(self, path: str) -> None:
        pass
    def add_favorite(self, path: str) -> None:
        pass
    def get_favorites(self) -> List[str]:
        pass
    def set_zoom(self, z: float) -> None:
        pass
    def get_zoom(self) -> float:
        pass

    class FileTreeNode:
        def __init__(self, path: str) -> None:
            pass
        path: Path
        read: bool
        children: List[FileTreeNode]

    class FileData:
        def __init__(self, path: Path) -> None:
            pass
        path: Path
        is_directory: bool
        size: int
        date_modified: int

        has_icon_preview: bool
        icon_preview: ImTextureID
        icon_preview_data: int
        icon_preview_width: int
        icon_preview_height: int
####################    </generated_from:ImFileDialog.h>    ####################

# </litgen_stub> // Autogenerated code end!
