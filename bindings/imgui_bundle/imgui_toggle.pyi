"""A toggle switch widget for Dear ImGui
Python bindings for https://github.com/cmdwtf/imgui_toggle
"""

from typing import Tuple, overload
import numpy as np
import enum


from imgui_bundle.imgui import ImColor, ImVec2, ImVec4

ToggleFlags = int
ToggleFlags_Default = ToggleFlags_.default
ToggleA11yStyle_Default = ToggleA11yStyle_.default


# ImGuiToggleConstants: A set of defaults and limits used by ImGuiToggleConfig
class ToggleConstants:
    # The golden ratio.
    Phi = 1.6180339887498948482045

    # d = 2r
    DiameterToRadiusRatio = 0.5

    # Animation is disabled with a animation_duration of 0.
    AnimationDurationDisabled = 0.0

    # The default animation duration, in seconds. (0.1: 100 ms.)
    AnimationDurationDefault = 0.1

    # The lowest allowable value for animation duration. (0.0: Disabled animation.)
    AnimationDurationMinimum = AnimationDurationDisabled

    # The default frame rounding value. (1.0: Full rounding.)
    FrameRoundingDefault = 1.0

    # The minimum frame rounding value. (0.0: Full rectangle.)
    FrameRoundingMinimum = 0.0

    # The maximum frame rounding value. (1.0: Full rounding.)
    FrameRoundingMaximum = 1.0

    # The default knob rounding value. (1.0: Full rounding.)
    KnobRoundingDefault = 1.0

    # The minimum knob rounding value. (0.0: Full rectangle.)
    KnobRoundingMinimum = 0.0

    # The maximum knob rounding value. (1.0: Full rounding.)
    KnobRoundingMaximum = 1.0

    # The default height to width ratio. (Phi: The golden ratio.)
    WidthRatioDefault = Phi

    # The minimum allowable width ratio. (1.0: Toggle width==height, not very useful but interesting.)
    WidthRatioMinimum = 1.0

    # The maximum allowable width ratio. (10.0: It starts to get silly quickly.)
    WidthRatioMaximum = 10.0

    # The default amount of pixels the knob should be inset into the toggle frame. (1.5 in each direction: Pleasing to the eye.)
    # ImOffsetRect KnobInsetDefault = 1.5

    # The minimum amount of pixels the knob should be negatively inset (outset) from the toggle frame. (-100.0: Big overgrown toggle.)
    KnobInsetMinimum = -100.0

    # The maximum amount of pixels the knob should be inset into the toggle frame. (100.0: Toggle likely invisible!)
    KnobInsetMaximum = 100.0

    # The default thickness for borders drawn on the toggle frame and knob.
    BorderThicknessDefault = 1.0

    # The default thickness for shadows drawn under the toggle frame and knob.
    ShadowThicknessDefault = 2.0

    # The default a11y string used when the toggle is on.
    LabelA11yOnDefault = "1"

    # The default a11y string used when the toggle is off.
    LabelA11yOffDefault = "0"



# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# <litgen_stub> // Autogenerated code below! Do not edit!
####################    <generated_from:imgui_toggle.h>    ####################
# Type forward declarations, definitions below in this file.

""" namespace ImGui"""
# Widgets: Toggle Switches
# - Toggles behave similarly to ImGui::Checkbox()
# - Sometimes called a toggle switch, see also: https://en.wikipedia.org/wiki/Toggle_switch_(widget)
# - They represent two mutually exclusive states, with an optional animation on the UI when toggled.
# Optional parameters:
# - flags: Values from the ImGuiToggleFlags_ enumeration to set toggle modes.
# - animation_duration: Animation duration. Amount of time in seconds the toggle should animate. (0,...] default: 1.0 (Overloads with this parameter imply ImGuiToggleFlags_Animated)
# - frame_rounding: A scalar that controls how rounded the toggle frame is. 0 is square, 1 is round. (0, 1) default 1.0
# - knob_rounding: A scalar that controls how rounded the toggle knob is. 0 is square, 1 is round. (0, 1) default 1.0
# - size: A width and height to draw the toggle at. Defaults to `ImGui::GetFrameHeight()` and that height * Phi for the width.
# Config structure:
# - The overload taking a reference to an ImGuiToggleConfig structure allows for more complete control over the widget.
# IMGUI_API bool Toggle(const char* label, bool* v, const ImVec2& size = ImVec2());    /* original C++ signature */
@overload
def toggle(label: str, v: bool, size: ImVec2 = ImVec2()) -> Tuple[bool, bool]:
    pass

# IMGUI_API bool Toggle(const char* label, bool* v, ImGuiToggleFlags flags, const ImVec2& size = ImVec2());    /* original C++ signature */
@overload
def toggle(
    label: str, v: bool, flags: ToggleFlags, size: ImVec2 = ImVec2()
) -> Tuple[bool, bool]:
    pass

# IMGUI_API bool Toggle(const char* label, bool* v, ImGuiToggleFlags flags, float animation_duration, const ImVec2& size = ImVec2());    /* original C++ signature */
@overload
def toggle(
    label: str,
    v: bool,
    flags: ToggleFlags,
    animation_duration: float,
    size: ImVec2 = ImVec2(),
) -> Tuple[bool, bool]:
    pass

# IMGUI_API bool Toggle(const char* label, bool* v, ImGuiToggleFlags flags, float frame_rounding, float knob_rounding, const ImVec2& size = ImVec2());    /* original C++ signature */
@overload
def toggle(
    label: str,
    v: bool,
    flags: ToggleFlags,
    frame_rounding: float,
    knob_rounding: float,
    size: ImVec2 = ImVec2(),
) -> Tuple[bool, bool]:
    pass

# IMGUI_API bool Toggle(const char* label, bool* v, ImGuiToggleFlags flags, float animation_duration, float frame_rounding, float knob_rounding, const ImVec2& size = ImVec2());    /* original C++ signature */
@overload
def toggle(
    label: str,
    v: bool,
    flags: ToggleFlags,
    animation_duration: float,
    frame_rounding: float,
    knob_rounding: float,
    size: ImVec2 = ImVec2(),
) -> Tuple[bool, bool]:
    pass

# IMGUI_API bool Toggle(const char* label, bool* v, const ImGuiToggleConfig& config);    /* original C++ signature */
@overload
def toggle(label: str, v: bool, config: ToggleConfig) -> Tuple[bool, bool]:
    pass

class ToggleFlags_(enum.Enum):
    """ImGuiToggleFlags: A set of flags that adjust behavior and display for ImGui::Toggle()."""

    # ImGuiToggleFlags_None                   = 0,    /* original C++ signature */
    none = enum.auto()  # (= 0)
    # ImGuiToggleFlags_Animated               = 1 << 0,     /* original C++ signature */
    animated = enum.auto()  # (= 1 << 0)  # The toggle's knob should be animated.
    # Bits 1-2 reserved.
    # ImGuiToggleFlags_BorderedFrame          = 1 << 3,     /* original C++ signature */
    bordered_frame = (
        enum.auto()
    )  # (= 1 << 3)  # The toggle should have a border drawn on the frame.
    # ImGuiToggleFlags_BorderedKnob           = 1 << 4,     /* original C++ signature */
    bordered_knob = (
        enum.auto()
    )  # (= 1 << 4)  # The toggle should have a border drawn on the knob.
    # ImGuiToggleFlags_ShadowedFrame          = 1 << 5,     /* original C++ signature */
    shadowed_frame = (
        enum.auto()
    )  # (= 1 << 5)  # The toggle should have a shadow drawn under the frame.
    # ImGuiToggleFlags_ShadowedKnob           = 1 << 6,     /* original C++ signature */
    shadowed_knob = (
        enum.auto()
    )  # (= 1 << 6)  # The toggle should have a shadow drawn under the knob.
    # Bit 7 reserved.
    # ImGuiToggleFlags_A11y                   = 1 << 8,     /* original C++ signature */
    a11y = (
        enum.auto()
    )  # (= 1 << 8)  # The toggle should draw on and off glyphs to help indicate its state.
    # ImGuiToggleFlags_Bordered               = ImGuiToggleFlags_BorderedFrame | ImGuiToggleFlags_BorderedKnob,     /* original C++ signature */
    bordered = (
        enum.auto()
    )  # (= ToggleFlags_BorderedFrame | ToggleFlags_BorderedKnob)  # Shorthand for bordered frame and knob.
    # ImGuiToggleFlags_Shadowed               = ImGuiToggleFlags_ShadowedFrame | ImGuiToggleFlags_ShadowedKnob,     /* original C++ signature */
    shadowed = (
        enum.auto()
    )  # (= ToggleFlags_ShadowedFrame | ToggleFlags_ShadowedKnob)  # Shorthand for shadowed frame and knob.
    # ImGuiToggleFlags_Default                = ImGuiToggleFlags_None,     /* original C++ signature */
    default = (
        enum.auto()
    )  # (= ToggleFlags_None)  # The default flags used when no ImGuiToggleFlags_ are specified.

class ToggleA11yStyle_(enum.Enum):
    """ImGuiToggleA11yStyle: Styles to draw A11y labels."""

    # ImGuiToggleA11yStyle_Label,                 /* original C++ signature */
    label = enum.auto()  # (= 0)  # A11y glyphs draw as text labels.
    # ImGuiToggleA11yStyle_Glyph,                 /* original C++ signature */
    glyph = enum.auto()  # (= 1)  # A11y glyphs draw as power-icon style "I/O" glyphs.
    # ImGuiToggleA11yStyle_Dot,                   /* original C++ signature */
    dot = (
        enum.auto()
    )  # (= 2)  # A11y glyphs draw as a small dot that can be colored separately from the frame.
    # ImGuiToggleA11yStyle_Default            = ImGuiToggleA11yStyle_Label,     /* original C++ signature */
    default = enum.auto()  # (= ToggleA11yStyle_Label)  # Default: text labels.

""" ImGuiToggleConstants: A set of defaults and limits used by ImGuiToggleConfig"""

class ToggleStateConfig:
    # float FrameBorderThickness = ImGuiToggleConstants::BorderThicknessDefault;    /* original C++ signature */
    # The thickness the border should be drawn on the frame when ImGuiToggleFlags_BorderedFrame is specified in `Flags`.
    frame_border_thickness: float = ToggleConstants.BorderThicknessDefault

    # float FrameShadowThickness = ImGuiToggleConstants::ShadowThicknessDefault;    /* original C++ signature */
    # The thickness the shadow should be drawn on the frame when ImGuiToggleFlags_ShadowedFrame is specified in `Flags`.
    frame_shadow_thickness: float = ToggleConstants.ShadowThicknessDefault

    # float KnobBorderThickness = ImGuiToggleConstants::BorderThicknessDefault;    /* original C++ signature */
    # The thickness the border should be drawn on the frame when ImGuiToggleFlags_BorderedKnob is specified in `Flags`.
    knob_border_thickness: float = ToggleConstants.BorderThicknessDefault

    # float KnobShadowThickness = ImGuiToggleConstants::ShadowThicknessDefault;    /* original C++ signature */
    # The thickness the shadow should be drawn on the frame when ImGuiToggleFlags_ShadowedKnob is specified in `Flags`.
    knob_shadow_thickness: float = ToggleConstants.ShadowThicknessDefault

    # const char* Label = nullptr;    /* original C++ signature */
    # The label drawn on the toggle to show the toggle is in the when ImGuiToggleFlags_A11yLabels is specified in `Flags`.
    # If left null, default strings will be used.
    label: str = None

    # ImOffsetRect KnobInset = ImGuiToggleConstants::KnobInsetDefault;    /* original C++ signature */
    # The number of pixels the knob should be inset into the toggle frame.
    # With a round (circle) knob, an average of each offset will be used.
    # With a rectangular knob, each offset will be used in it's intended direction.
    knob_inset: ImOffsetRect = ToggleConstants.KnobInsetDefault

    # ImVec2 KnobOffset = ImVec2(0.0f, 0.0f);    /* original C++ signature */
    # A custom amount of pixels to offset the knob by. Positive x values will move the knob towards the inside, negative the outside.
    knob_offset: ImVec2 = ImVec2(0.0, 0.0)

    # const ImGuiTogglePalette* Palette = nullptr;    /* original C++ signature */
    # An optional custom palette to use for the colors to use when drawing the toggle. If left null, theme colors will be used.
    # If any of the values in the palette are zero, those specific colors will default to theme colors.
    palette: TogglePalette = None
    def __init__(self) -> None:
        """Autogenerated default constructor"""
        pass

class ToggleConfig:
    """ImGuiToggleConfig: A collection of data used to customize the appearance and behavior of a toggle widget."""

    # ImGuiToggleFlags Flags = ImGuiToggleFlags_Default;    /* original C++ signature */
    # Flags that control the toggle's behavior and display.
    flags: ToggleFlags = ToggleFlags_Default

    # ImGuiToggleFlags A11yStyle = ImGuiToggleA11yStyle_Default;    /* original C++ signature */
    # What style of A11y glyph to draw on the widget.
    a11y_style: ToggleFlags = ToggleA11yStyle_Default

    # float AnimationDuration = ImGuiToggleConstants::AnimationDurationDefault;    /* original C++ signature */
    # The a duration in seconds that the toggle should animate for. If 0, animation will be disabled.
    animation_duration: float = ToggleConstants.AnimationDurationDefault

    # float FrameRounding = ImGuiToggleConstants::FrameRoundingDefault;    /* original C++ signature */
    # A scalar that controls how rounded the toggle frame is. 0 is square, 1 is round. (0, 1) default 1.0
    frame_rounding: float = ToggleConstants.FrameRoundingDefault

    # float KnobRounding = ImGuiToggleConstants::KnobRoundingDefault;    /* original C++ signature */
    # A scalar that controls how rounded the toggle knob is. 0 is square, 1 is round. (0, 1) default 1.0
    knob_rounding: float = ToggleConstants.KnobRoundingDefault

    # float WidthRatio = ImGuiToggleConstants::WidthRatioDefault;    /* original C++ signature */
    # A ratio that controls how wide the toggle is compared to it's height. If `Size.x` is non-zero, this value is ignored.
    width_ratio: float = ToggleConstants.WidthRatioDefault

    # ImVec2 Size = ImVec2(0.0f, 0.0f);    /* original C++ signature */
    # A custom size to draw the toggle with. Defaults to (0, 0). If `Size.x` is zero, `WidthRatio` will control the toggle width.
    # If `Size.y` is zero, the toggle height will be set by `ImGui::GetFrameHeight()`.
    size: ImVec2 = ImVec2(0.0, 0.0)

    # ImGuiToggleStateConfig On;    /* original C++ signature */
    # Specific configuration data to use when the knob is in the on state.
    on: ToggleStateConfig

    # ImGuiToggleStateConfig Off;    /* original C++ signature */
    # Specific configuration data to use when the knob is in the off state.
    off: ToggleStateConfig
    def __init__(self) -> None:
        """Autogenerated default constructor"""
        pass
####################    </generated_from:imgui_toggle.h>    ####################


####################    <generated_from:imgui_toggle_presets.h>    ####################
""" ImGuiTogglePresets: A few canned configurations for various presets OOTB."""
# ImGuiToggleConfig DefaultStyle();    /* original C++ signature */
def default_style() -> ToggleConfig:
    """The default, unmodified style.
    (private API)
    """
    pass

# ImGuiToggleConfig RectangleStyle();    /* original C++ signature */
def rectangle_style() -> ToggleConfig:
    """A style similar to default, but with rectangular knob and frame.
    (private API)
    """
    pass

# ImGuiToggleConfig GlowingStyle();    /* original C++ signature */
def glowing_style() -> ToggleConfig:
    """A style that uses a shadow to appear to glow while it's on.
    (private API)
    """
    pass

# ImGuiToggleConfig iOSStyle(float size_scale = 1.0f, bool light_mode = false);    /* original C++ signature */
def ios_style(size_scale: float = 1.0, light_mode: bool = False) -> ToggleConfig:
    """A style that emulates what a toggle on iOS looks like.
    (private API)
    """
    pass

# ImGuiToggleConfig MaterialStyle(float size_scale = 1.0f);    /* original C++ signature */
def material_style(size_scale: float = 1.0) -> ToggleConfig:
    """A style that emulates what a Material Design toggle looks like.
    (private API)
    """
    pass

# ImGuiToggleConfig MinecraftStyle(float size_scale = 1.0f);    /* original C++ signature */
# }
def minecraft_style(size_scale: float = 1.0) -> ToggleConfig:
    """A style that emulates what a toggle close to one from Minecraft.
    (private API)
    """
    pass
####################    </generated_from:imgui_toggle_presets.h>    ####################


####################    <generated_from:imgui_toggle_palette.h>    ####################
class TogglePalette:
    """ImGuiTogglePalette: A collection of colors used to customize the rendering of a toggle widget.
    Leaving any ImVec4 as default (zero) will allow the theme color to be used for that member.
    """

    # ImVec4 Knob;    /* original C++ signature */
    # The default knob color.
    knob: ImVec4

    # ImVec4 KnobHover;    /* original C++ signature */
    # The default knob color, used when when the knob is hovered.
    knob_hover: ImVec4

    # ImVec4 Frame;    /* original C++ signature */
    # The background color of the toggle frame.
    frame: ImVec4

    # ImVec4 FrameHover;    /* original C++ signature */
    # The background color of the toggle frame when the toggle is hovered.
    frame_hover: ImVec4

    # ImVec4 FrameBorder;    /* original C++ signature */
    # The background color of the toggle frame's border used when ImGuiToggleFlags_BorderedFrame is specified.
    frame_border: ImVec4

    # ImVec4 FrameShadow;    /* original C++ signature */
    # The shadow color of the toggle frame.
    frame_shadow: ImVec4

    # ImVec4 KnobBorder;    /* original C++ signature */
    # The background color of the toggle knob's border used when ImGuiToggleFlags_BorderedKnob is specified.
    knob_border: ImVec4

    # ImVec4 KnobShadow;    /* original C++ signature */
    # The shadow color of the toggle knob.
    knob_shadow: ImVec4

    # ImVec4 A11yGlyph;    /* original C++ signature */
    # The color of the accessibility label or glyph.
    a11y_glyph: ImVec4
    def __init__(self) -> None:
        """Autogenerated default constructor"""
        pass

# void UnionPalette(ImGuiTogglePalette* target, const ImGuiTogglePalette* candidate, const ImVec4 colors[], bool v);    /* original C++ signature */
def union_palette(
    target: TogglePalette, candidate: TogglePalette, colors: ImVec4, v: bool
) -> None:
    """(private API)"""
    pass

# void BlendPalettes(ImGuiTogglePalette* result, const ImGuiTogglePalette& a, const ImGuiTogglePalette& b, float blend_amount);    /* original C++ signature */
# }
def blend_palettes(
    result: TogglePalette, a: TogglePalette, b: TogglePalette, blend_amount: float
) -> None:
    """(private API)"""
    pass
####################    </generated_from:imgui_toggle_palette.h>    ####################


####################    <generated_from:imgui_offset_rect.h>    ####################
class ImOffsetRect:
    """Helper: ImOffsetRect A set of offsets to apply to an ImRect."""

    # constexpr ImOffsetRect()                                                    : Top(0.0f), Left(0.0f), Bottom(0.0f), Right(0.0f)                  {}    /* original C++ signature */
    @overload
    def __init__(self) -> None:
        pass
    # constexpr ImOffsetRect(const ImVec2& topLeft, const ImVec2& bottomRight)    : ImOffsetRect(topLeft.y, topLeft.x, bottomRight.y, bottomRight.x)  {}    /* original C++ signature */
    @overload
    def __init__(self, top_left: ImVec2, bottom_right: ImVec2) -> None:
        pass
    # constexpr ImOffsetRect(const ImVec4& v)                                     : ImOffsetRect(v.x, v.y, v.z, v.w)                                  {}    /* original C++ signature */
    @overload
    def __init__(self, v: ImVec4) -> None:
        pass
    # constexpr ImOffsetRect(float top, float left, float bottom, float right)    : Top(top), Left(left), Bottom(bottom), Right(right)                {}    /* original C++ signature */
    @overload
    def __init__(self, top: float, left: float, bottom: float, right: float) -> None:
        pass
    # constexpr ImOffsetRect(float all)                                           : Top(all), Left(all), Bottom(all), Right(all)                      {}    /* original C++ signature */
    @overload
    def __init__(self, all: float) -> None:
        pass
    # ImVec2      GetSize() const { return ImVec2(Left + Right, Top + Bottom); }    /* original C++ signature */
    def get_size(self) -> ImVec2:
        """(private API)"""
        pass
    # float       GetWidth() const { return Left + Right; }    /* original C++ signature */
    def get_width(self) -> float:
        """(private API)"""
        pass
    # float       GetHeight() const { return Top + Bottom; }    /* original C++ signature */
    def get_height(self) -> float:
        """(private API)"""
        pass
    # float       GetAverage() const { return (Top + Left + Bottom + Right) / 4.0f; }    /* original C++ signature */
    def get_average(self) -> float:
        """(private API)"""
        pass
    # ImOffsetRect MirrorHorizontally() const { return ImOffsetRect(Top, Right, Bottom, Left); }    /* original C++ signature */
    def mirror_horizontally(self) -> ImOffsetRect:
        """(private API)"""
        pass
    # ImOffsetRect MirrorVertically() const { return ImOffsetRect(Bottom, Left, Top, Right); }    /* original C++ signature */
    def mirror_vertically(self) -> ImOffsetRect:
        """(private API)"""
        pass
    # ImOffsetRect Mirror() const { return ImOffsetRect(Bottom, Right, Top, Left); }    /* original C++ signature */
    def mirror(self) -> ImOffsetRect:
        """(private API)"""
        pass
####################    </generated_from:imgui_offset_rect.h>    ####################

# </litgen_stub> // Autogenerated code end!
