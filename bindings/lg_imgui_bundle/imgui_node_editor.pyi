# type: ignore
import sys
from typing import Literal, List, Any, Optional, Tuple, Dict
import numpy as np
import enum
import numpy
from lg_imgui_bundle.imgui import ImVec2, ImVec4

class NodeId:
    def __init__(self, id: int):
        pass
    def id(self) -> int:
        pass


class LinkId:
    def __init__(self, id: int):
        pass
    def id(self) -> int:
        pass


class PinId:
    def __init__(self, id: int):
        pass
    def id(self) -> int:
        pass


# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# <litgen_stub> // Autogenerated code below! Do not edit!
####################    <generated_from:imgui_node_editor.h>    ####################
#------------------------------------------------------------------------------
# VERSION 0.9.1
#
# LICENSE
#   This software is dual-licensed to the public domain and under the following
#   license: you are granted a perpetual, irrevocable license to copy, modify,
#   publish, and distribute this file as you see fit.
#
# CREDITS
#   Written by Michal Cichon
#------------------------------------------------------------------------------


#------------------------------------------------------------------------------


#------------------------------------------------------------------------------


"""------------------------------------------------------------------------------"""
""" namespace Editor"""


#------------------------------------------------------------------------------


class PinKind(enum.Enum):
    """------------------------------------------------------------------------------"""
    input = enum.auto()  # (= 0)
    output = enum.auto() # (= 1)

class FlowDirection(enum.Enum):
    forward = enum.auto()  # (= 0)
    backward = enum.auto() # (= 1)

class CanvasSizeMode(enum.Enum):
    fit_vertical_view = enum.auto()   # (= 0)  # Previous view will be scaled to fit new view on Y axis
    fit_horizontal_view = enum.auto() # (= 1)  # Previous view will be scaled to fit new view on X axis
    center_only = enum.auto()         # (= 2)  # Previous view will be centered on new view







class Config:

    settings_file: str
    user_pointer: Any
    custom_zoom_levels: ImVector<float>
    canvas_size_mode: CanvasSizeModeAlias
    drag_button_index: int          # Mouse button index drag action will react to (0-left, 1-right, 2-middle)
    select_button_index: int        # Mouse button index select action will react to (0-left, 1-right, 2-middle)
    navigate_button_index: int      # Mouse button index navigate action will react to (0-left, 1-right, 2-middle)
    context_menu_button_index: int  # Mouse button index context menu action will react to (0-left, 1-right, 2-middle)

    def __init__(self) -> None:
        pass


class StyleColor(enum.Enum):
    """------------------------------------------------------------------------------"""
    bg = enum.auto()                    # (= 0)
    grid = enum.auto()                  # (= 1)
    node_bg = enum.auto()               # (= 2)
    node_border = enum.auto()           # (= 3)
    hov_node_border = enum.auto()       # (= 4)
    sel_node_border = enum.auto()       # (= 5)
    node_sel_rect = enum.auto()         # (= 6)
    node_sel_rect_border = enum.auto()  # (= 7)
    hov_link_border = enum.auto()       # (= 8)
    sel_link_border = enum.auto()       # (= 9)
    highlight_link_border = enum.auto() # (= 10)
    link_sel_rect = enum.auto()         # (= 11)
    link_sel_rect_border = enum.auto()  # (= 12)
    pin_rect = enum.auto()              # (= 13)
    pin_rect_border = enum.auto()       # (= 14)
    flow = enum.auto()                  # (= 15)
    flow_marker = enum.auto()           # (= 16)
    group_bg = enum.auto()              # (= 17)
    group_border = enum.auto()          # (= 18)

    count = enum.auto()                 # (= 19)

class StyleVar(enum.Enum):
    node_padding = enum.auto()               # (= 0)
    node_rounding = enum.auto()              # (= 1)
    node_border_width = enum.auto()          # (= 2)
    hovered_node_border_width = enum.auto()  # (= 3)
    selected_node_border_width = enum.auto() # (= 4)
    pin_rounding = enum.auto()               # (= 5)
    pin_border_width = enum.auto()           # (= 6)
    link_strength = enum.auto()              # (= 7)
    source_direction = enum.auto()           # (= 8)
    target_direction = enum.auto()           # (= 9)
    scroll_duration = enum.auto()            # (= 10)
    flow_marker_distance = enum.auto()       # (= 11)
    flow_speed = enum.auto()                 # (= 12)
    flow_duration = enum.auto()              # (= 13)
    pivot_alignment = enum.auto()            # (= 14)
    pivot_size = enum.auto()                 # (= 15)
    pivot_scale = enum.auto()                # (= 16)
    pin_corners = enum.auto()                # (= 17)
    pin_radius = enum.auto()                 # (= 18)
    pin_arrow_size = enum.auto()             # (= 19)
    pin_arrow_width = enum.auto()            # (= 20)
    group_rounding = enum.auto()             # (= 21)
    group_border_width = enum.auto()         # (= 22)
    highlight_connected_links = enum.auto()  # (= 23)
    snap_link_to_pin_dir = enum.auto()       # (= 24)

    count = enum.auto()                      # (= 25)

class Style:
    node_padding: ImVec4
    node_rounding: float
    node_border_width: float
    hovered_node_border_width: float
    selected_node_border_width: float
    pin_rounding: float
    pin_border_width: float
    link_strength: float
    source_direction: ImVec2
    target_direction: ImVec2
    scroll_duration: float
    flow_marker_distance: float
    flow_speed: float
    flow_duration: float
    pivot_alignment: ImVec2
    pivot_size: ImVec2
    pivot_scale: ImVec2
    pin_corners: float
    pin_radius: float
    pin_arrow_size: float
    pin_arrow_width: float
    group_rounding: float
    group_border_width: float
    highlight_connected_links: float
    snap_link_to_pin_dir: float  # when True link will start on the line defined by pin direction

    def __init__(self) -> None:
        pass




#------------------------------------------------------------------------------
def set_current_editor(ctx: EditorContext) -> None:
    pass
def get_current_editor() -> EditorContext:
    pass
def create_editor(config: Config = None) -> EditorContext:
    pass
def destroy_editor(ctx: EditorContext) -> None:
    pass
def get_config(ctx: EditorContext = None) -> Config:
    pass

def get_style() -> Style:
    pass
def get_style_color_name(color_index: StyleColor) -> str:
    pass

def push_style_color(color_index: StyleColor, color: ImVec4) -> None:
    pass
def pop_style_color(count: int = 1) -> None:
    pass

def push_style_var(var_index: StyleVar, value: float) -> None:
    pass
def push_style_var(var_index: StyleVar, value: ImVec2) -> None:
    pass
def push_style_var(var_index: StyleVar, value: ImVec4) -> None:
    pass
def pop_style_var(count: int = 1) -> None:
    pass

def begin(id: str, size: ImVec2 = ImVec2(0, 0)) -> None:
    pass
def end() -> None:
    pass

def begin_node(id: NodeId) -> None:
    pass
def begin_pin(id: PinId, kind: PinKind) -> None:
    pass
def pin_rect(a: ImVec2, b: ImVec2) -> None:
    pass
def pin_pivot_rect(a: ImVec2, b: ImVec2) -> None:
    pass
def pin_pivot_size(size: ImVec2) -> None:
    pass
def pin_pivot_scale(scale: ImVec2) -> None:
    pass
def pin_pivot_alignment(alignment: ImVec2) -> None:
    pass
def end_pin() -> None:
    pass
def group(size: ImVec2) -> None:
    pass
def end_node() -> None:
    pass

def begin_group_hint(node_id: NodeId) -> bool:
    pass
def get_group_min() -> ImVec2:
    pass
def get_group_max() -> ImVec2:
    pass
def get_hint_foreground_draw_list() -> ImDrawList:
    pass
def get_hint_background_draw_list() -> ImDrawList:
    pass
def end_group_hint() -> None:
    pass

def get_node_background_draw_list(node_id: NodeId) -> ImDrawList:
    """ TODO: Add a way to manage node background channels"""
    pass

def link(
    id: LinkId,
    start_pin_id: PinId,
    end_pin_id: PinId,
    color: ImVec4 = ImVec4(1, 1, 1, 1),
    thickness: float = 1.0
    ) -> bool:
    pass

def flow(
    link_id: LinkId,
    direction: FlowDirection = FlowDirection.forward
    ) -> None:
    pass

def begin_create(
    color: ImVec4 = ImVec4(1, 1, 1, 1),
    thickness: float = 1.0
    ) -> bool:
    pass
def query_new_link(start_id: PinId, end_id: PinId) -> bool:
    pass
def query_new_link(
    start_id: PinId,
    end_id: PinId,
    color: ImVec4,
    thickness: float = 1.0
    ) -> bool:
    pass
def query_new_node(pin_id: PinId) -> bool:
    pass
def query_new_node(
    pin_id: PinId,
    color: ImVec4,
    thickness: float = 1.0
    ) -> bool:
    pass
def accept_new_item() -> bool:
    pass
def accept_new_item(color: ImVec4, thickness: float = 1.0) -> bool:
    pass
def reject_new_item() -> None:
    pass
def reject_new_item(color: ImVec4, thickness: float = 1.0) -> None:
    pass
def end_create() -> None:
    pass

def begin_delete() -> bool:
    pass
def query_deleted_link(
    link_id: LinkId,
    start_id: PinId = None,
    end_id: PinId = None
    ) -> bool:
    pass
def query_deleted_node(node_id: NodeId) -> bool:
    pass
def accept_deleted_item(delete_dependencies: bool = True) -> bool:
    pass
def reject_deleted_item() -> None:
    pass
def end_delete() -> None:
    pass

def set_node_position(node_id: NodeId, editor_position: ImVec2) -> None:
    pass
def set_group_size(node_id: NodeId, size: ImVec2) -> None:
    pass
def get_node_position(node_id: NodeId) -> ImVec2:
    pass
def get_node_size(node_id: NodeId) -> ImVec2:
    pass
def center_node_on_screen(node_id: NodeId) -> None:
    pass
def set_node_z_position(node_id: NodeId, z: float) -> None:
    """ Sets node z position, nodes with higher value are drawn over nodes with lower value"""
    pass
def get_node_z_position(node_id: NodeId) -> float:
    """ Returns node z position, defaults is 0.0"""
    pass

def restore_node_state(node_id: NodeId) -> None:
    pass

def suspend() -> None:
    pass
def resume() -> None:
    pass
def is_suspended() -> bool:
    pass

def is_active() -> bool:
    pass

def has_selection_changed() -> bool:
    pass
def get_selected_object_count() -> int:
    pass
def get_selected_nodes(nodes: NodeId, size: int) -> int:
    pass
def get_selected_links(links: LinkId, size: int) -> int:
    pass
def is_node_selected(node_id: NodeId) -> bool:
    pass
def is_link_selected(link_id: LinkId) -> bool:
    pass
def clear_selection() -> None:
    pass
def select_node(node_id: NodeId, append: bool = False) -> None:
    pass
def select_link(link_id: LinkId, append: bool = False) -> None:
    pass
def deselect_node(node_id: NodeId) -> None:
    pass
def deselect_link(link_id: LinkId) -> None:
    pass

def delete_node(node_id: NodeId) -> bool:
    pass
def delete_link(link_id: LinkId) -> bool:
    pass

def has_any_links(node_id: NodeId) -> bool:
    """ Returns True if node has any link connected"""
    pass
def has_any_links(pin_id: PinId) -> bool:
    """ Return True if pin has any link connected"""
    pass
def break_links(node_id: NodeId) -> int:
    """ Break all links connected to this node"""
    pass
def break_links(pin_id: PinId) -> int:
    """ Break all links connected to this pin"""
    pass

def navigate_to_content(duration: float = -1) -> None:
    pass
def navigate_to_selection(zoom_in: bool = False, duration: float = -1) -> None:
    pass

def show_node_context_menu(node_id: NodeId) -> bool:
    pass
def show_pin_context_menu(pin_id: PinId) -> bool:
    pass
def show_link_context_menu(link_id: LinkId) -> bool:
    pass
def show_background_context_menu() -> bool:
    pass

def enable_shortcuts(enable: bool) -> None:
    pass
def are_shortcuts_enabled() -> bool:
    pass

def begin_shortcut() -> bool:
    pass
def accept_cut() -> bool:
    pass
def accept_copy() -> bool:
    pass
def accept_paste() -> bool:
    pass
def accept_duplicate() -> bool:
    pass
def accept_create_node() -> bool:
    pass
def get_action_context_size() -> int:
    pass
def get_action_context_nodes(nodes: NodeId, size: int) -> int:
    pass
def get_action_context_links(links: LinkId, size: int) -> int:
    pass
def end_shortcut() -> None:
    pass

def get_current_zoom() -> float:
    pass

def get_hovered_node() -> NodeId:
    pass
def get_hovered_pin() -> PinId:
    pass
def get_hovered_link() -> LinkId:
    pass
def get_double_clicked_node() -> NodeId:
    pass
def get_double_clicked_pin() -> PinId:
    pass
def get_double_clicked_link() -> LinkId:
    pass
def is_background_clicked() -> bool:
    pass
def is_background_double_clicked() -> bool:
    pass
def get_background_click_button_index() -> ImGuiMouseButton:
    """ -1 if none"""
    pass
def get_background_double_click_button_index() -> ImGuiMouseButton:
    """ -1 if none"""
    pass

def get_link_pins(
    link_id: LinkId,
    start_pin_id: PinId,
    end_pin_id: PinId
    ) -> bool:
    """ pass None if particular pin do not interest you"""
    pass

def pin_had_any_links(pin_id: PinId) -> bool:
    pass

def get_screen_size() -> ImVec2:
    pass
def screen_to_canvas(pos: ImVec2) -> ImVec2:
    pass
def canvas_to_screen(pos: ImVec2) -> ImVec2:
    pass

def get_node_count() -> int:
    """ Returns number of submitted nodes since Begin() call"""
    pass
def get_ordered_node_ids(nodes: NodeId, size: int) -> int:
    """ Fills an array with node id's in order they're drawn; up to 'size` elements are set. Returns actual size of filled id's."""
    pass







#------------------------------------------------------------------------------





#------------------------------------------------------------------------------


# namespace ax


#------------------------------------------------------------------------------####################    </generated_from:imgui_node_editor.h>    ####################

# </litgen_stub> // Autogenerated code end!