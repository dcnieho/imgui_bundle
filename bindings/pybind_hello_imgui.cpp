#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "hello_imgui/hello_imgui.h"
#include "hello_imgui/hello_imgui_screenshot.h"

namespace py = pybind11;


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// <litgen_glue_code>  // Autogenerated code below! Do not edit!

// </litgen_glue_code> // Autogenerated code end
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE END !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


py::array_t<uint8_t> FinalAppWindowScreenshot()
{
    auto imageBuffer = HelloImGui::FinalAppWindowScreenshotRgbBuffer();

    std::vector<std::size_t> shape{
        imageBuffer.height,
        imageBuffer.width,
        3
    };
    std::vector<std::size_t> stride{
        imageBuffer.width * 3,
        3,
        1
    };
    py::array_t<uint8_t> r(
        shape,
        stride,
        imageBuffer.bufferRgb.data());
    return r;
}

void py_init_module_hello_imgui(py::module& m)
{
    using namespace HelloImGui;

    m.def("final_app_window_screenshot", FinalAppWindowScreenshot);

    m.def("_glfw_pointer", [](const RunnerParams& params) {
       return (size_t)params.backendPointers.glfwWindow;
    });


    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // <litgen_pydef> // Autogenerated code below! Do not edit!
    ////////////////////    <generated_from:hello_imgui_amalgamation.h>    ////////////////////
    auto pyClassAssetFileData =
        py::class_<HelloImGui::AssetFileData>
            (m, "AssetFileData", "*\n@@md#LoadAssetFileData\n\n* `AssetFileData LoadAssetFileData(const char *assetPath)` will load an entire asset file into memory.\n This works on all platforms, including android.\n ````cpp\n    struct AssetFileData\n    {\n        None * data = None;\n        size_t dataSize = 0;\n    };\n ````\n* `FreeAssetFileData(AssetFileData * assetFileData)` will free the memory.\n\n  Note about ImGui: \"ImGui::GetIO().Fonts->AddFontFromMemoryTTF\" takes ownership of the data\n  and will free the memory for you.\n\n@@md\n*")
        .def(py::init<>()) // implicit default constructor
        .def_readwrite("data", &HelloImGui::AssetFileData::data, "")
        .def_readwrite("data_size", &HelloImGui::AssetFileData::dataSize, "")
        ;


    m.def("load_asset_file_data",
        HelloImGui::LoadAssetFileData, py::arg("asset_path"));

    m.def("free_asset_file_data",
        HelloImGui::FreeAssetFileData, py::arg("asset_file_data"));

    m.def("asset_file_full_path",
        HelloImGui::assetFileFullPath,
        py::arg("asset_relative_filename"),
        "*\n@@md#assetFileFullPath\n\n`std::string assetFileFullPath(const std::string& assetRelativeFilename)` will return the path to assets.\n\nThis works under all platforms __except Android__.\nFor compatibility with Android and other platforms, prefer to use `LoadAssetFileData` whenever possible.\n\n* Under iOS it will give a path in the app bundle (/private/XXX/....)\n* Under emscripten, it will be stored in the virtual filesystem at \"/\"\n* Under Android, assetFileFullPath is *not* implemented, and will throw an error:\n  assets can be compressed under android, and you cannot use standard file operations!\n  Use LoadAssetFileData instead\n\n@@md\n");

    m.def("override_assets_folder",
        HelloImGui::overrideAssetsFolder, py::arg("folder"));

    m.def("set_assets_folder",
        HelloImGui::setAssetsFolder, py::arg("folder"));


    m.def("image_from_asset",
        HelloImGui::ImageFromAsset, py::arg("asset_path"), py::arg("size") = ImVec2(0, 0), py::arg("uv0") = ImVec2(0, 0), py::arg("uv1") = ImVec2(1,1), py::arg("tint_col") = ImVec4(1,1,1,1), py::arg("border_col") = ImVec4(0,0,0,0));

    m.def("image_button_from_asset",
        HelloImGui::ImageButtonFromAsset, py::arg("asset_path"), py::arg("size") = ImVec2(0, 0), py::arg("uv0") = ImVec2(0, 0), py::arg("uv1") = ImVec2(1,1), py::arg("frame_padding") = -1, py::arg("bg_col") = ImVec4(0,0,0,0), py::arg("tint_col") = ImVec4(1,1,1,1));

    m.def("im_texture_id_from_asset",
        HelloImGui::ImTextureIdFromAsset, py::arg("asset_path"));


    auto pyClassScreenBounds =
        py::class_<HelloImGui::ScreenBounds>
            (m, "ScreenBounds", "")
        .def(py::init<>()) // implicit default constructor
        .def_readwrite("position", &HelloImGui::ScreenBounds::position, "")
        .def_readwrite("size", &HelloImGui::ScreenBounds::size, "")
        .def("top_left_corner",
            &HelloImGui::ScreenBounds::TopLeftCorner)
        .def("bottom_right_corner",
            &HelloImGui::ScreenBounds::BottomRightCorner)
        .def("center",
            &HelloImGui::ScreenBounds::Center)
        .def("contains",
            &HelloImGui::ScreenBounds::Contains, py::arg("pixel"))
        .def("win_position_centered",
            &HelloImGui::ScreenBounds::WinPositionCentered, py::arg("window_size"))
        .def("distance_from_pixel",
            &HelloImGui::ScreenBounds::DistanceFromPixel, py::arg("point"))
        .def("ensure_window_fits_this_monitor",
            &HelloImGui::ScreenBounds::EnsureWindowFitsThisMonitor, py::arg("window_bounds_original"))
        .def("__eq__",
            &HelloImGui::ScreenBounds::operator==, py::arg("other"))
        ;


    py::enum_<HelloImGui::FullScreenMode>(m, "FullScreenMode", py::arithmetic(), "")
        .value("no_full_screen", HelloImGui::FullScreenMode::NoFullScreen, "")
        .value("full_screen", HelloImGui::FullScreenMode::FullScreen, "Full screen with specified resolution")
        .value("full_screen_desktop_resolution", HelloImGui::FullScreenMode::FullScreenDesktopResolution, "Full screen with current desktop mode & resolution")
        .value("full_monitor_work_area", HelloImGui::FullScreenMode::FullMonitorWorkArea, "Fake full screen, maximized window on the selected monitor");


    py::enum_<HelloImGui::WindowSizeState>(m, "WindowSizeState", py::arithmetic(), "")
        .value("standard", HelloImGui::WindowSizeState::Standard, "")
        .value("minimized", HelloImGui::WindowSizeState::Minimized, "")
        .value("maximized", HelloImGui::WindowSizeState::Maximized, "");


    py::enum_<HelloImGui::WindowPositionMode>(m, "WindowPositionMode", py::arithmetic(), "")
        .value("os_default", HelloImGui::WindowPositionMode::OsDefault, "")
        .value("monitor_center", HelloImGui::WindowPositionMode::MonitorCenter, "")
        .value("from_coords", HelloImGui::WindowPositionMode::FromCoords, "");


    auto pyClassWindowGeometry =
        py::class_<HelloImGui::WindowGeometry>
            (m, "WindowGeometry", "*\n@@md#WindowGeometry\n\n__WindowGeometry__ is a struct that defines the window geometry.\n\nMembers:\n* `size`: _int[2], default=\"{800, 600}\"_. Size of the application window\n  used if fullScreenMode==NoFullScreen and sizeAuto==False\n* `sizeAuto`: _bool, default=false_\n  If True, adapt the app window size to the presented widgets\n* `fullScreenMode`: _FullScreenMode, default=NoFullScreen_.\n   You can choose between several full screen modes:\n   ````cpp\n        NoFullScreen,\n        FullScreen,                    // Full screen with specified resolution\n        FullScreenDesktopResolution,   // Full screen with current desktop mode & resolution\n        FullMonitorWorkArea            // Fake full screen, maximized window on the selected monitor\n    ````\n* `positionMode`: _WindowPositionMode, default = OsDefault_.\n   You can choose between several window position modes:\n   ````cpp\n        OsDefault,\n        MonitorCenter,\n        FromCoords,\n    ````\n* `monitorIdx`: _int, default = 0_.\n  used if positionMode==MonitorCenter or if fullScreenMode!=NoFullScreen\n* `windowSizeState`: _WindowSizeState, default=Standard_\n   You can choose between several window size states:\n   ````cpp\n        Standard,\n        Minimized,\n        Maximized\n    ````\n@@md\n*")
        .def(py::init<>()) // implicit default constructor
        .def_readwrite("size", &HelloImGui::WindowGeometry::size, "used if fullScreenMode==NoFullScreen and sizeAuto==False")
        .def_readwrite("size_auto", &HelloImGui::WindowGeometry::sizeAuto, "If True, adapt the app window size to the presented widgets")
        .def_readwrite("full_screen_mode", &HelloImGui::WindowGeometry::fullScreenMode, "")
        .def_readwrite("position_mode", &HelloImGui::WindowGeometry::positionMode, "")
        .def_readwrite("position", &HelloImGui::WindowGeometry::position, "used if windowPositionMode==FromCoords")
        .def_readwrite("monitor_idx", &HelloImGui::WindowGeometry::monitorIdx, "used if positionMode==MonitorCenter or if fullScreenMode!=NoFullScreen")
        .def_readwrite("window_size_state", &HelloImGui::WindowGeometry::windowSizeState, "")
        ;


    auto pyClassAppWindowParams =
        py::class_<HelloImGui::AppWindowParams>
            (m, "AppWindowParams", "*\n@@md#AppWindowParams\n\n__AppWindowParams__ is a struct that defines the application window display params.\nSee [doc_src/hello_imgui_diagram.png](https://raw.githubusercontent.com/pthom/hello_imgui/master/src/hello_imgui/doc_src/hello_imgui_diagram.png)\nfor details.\n\nMembers:\n* `windowTitle`: _string, default=\"\"_. Title of the application window\n* `windowGeometry`: _WindowGeometry_\n  Enables to precisely set the window geometry (position, monitor, size, full screen, fake full screen, etc.)\n   _Note: on a mobile device, the application will always be full screen._\n* `restorePreviousGeometry`: _bool, default=false_.\n  If True, then save & restore windowGeometry from last run (the geometry will be written in imgui_app_window.ini)\n* `borderless`: _bool, default = false_.\n* `resizable`: _bool, default = false_.\n\nOutput Member:\n* `outWindowDpiFactor`: _float, default = 1_.\n   This value is filled by HelloImGui during the window initialisation. On Windows and Linux, it can be > 1\n   on high resolution monitors (on MacOS, the scaling is handled by the system).\n   When loading fonts, their size should be multiplied by this factor.\n@@md\n*")
        .def(py::init<>()) // implicit default constructor
        .def_readwrite("window_title", &HelloImGui::AppWindowParams::windowTitle, "")
        .def_readwrite("window_geometry", &HelloImGui::AppWindowParams::windowGeometry, "")
        .def_readwrite("restore_previous_geometry", &HelloImGui::AppWindowParams::restorePreviousGeometry, "if True, then save & restore from last run")
        .def_readwrite("borderless", &HelloImGui::AppWindowParams::borderless, "")
        .def_readwrite("resizable", &HelloImGui::AppWindowParams::resizable, "")
        .def_readwrite("out_window_dpi_factor", &HelloImGui::AppWindowParams::outWindowDpiFactor, "")
        ;


    py::enum_<ImGuiTheme::ImGuiTheme_>(m, "ImGuiTheme_", py::arithmetic(), "")
        .value("imgui_colors_classic", ImGuiTheme::ImGuiTheme_ImGuiColorsClassic, "")
        .value("imgui_colors_dark", ImGuiTheme::ImGuiTheme_ImGuiColorsDark, "")
        .value("imgui_colors_light", ImGuiTheme::ImGuiTheme_ImGuiColorsLight, "")
        .value("material_flat", ImGuiTheme::ImGuiTheme_MaterialFlat, "")
        .value("photoshop_style", ImGuiTheme::ImGuiTheme_PhotoshopStyle, "")
        .value("gray_variations", ImGuiTheme::ImGuiTheme_GrayVariations, "")
        .value("gray_variations_darker", ImGuiTheme::ImGuiTheme_GrayVariations_Darker, "")
        .value("microsoft_style", ImGuiTheme::ImGuiTheme_MicrosoftStyle, "")
        .value("cherry", ImGuiTheme::ImGuiTheme_Cherry, "")
        .value("darcula", ImGuiTheme::ImGuiTheme_Darcula, "")
        .value("darcula_darker", ImGuiTheme::ImGuiTheme_DarculaDarker, "")
        .value("light_rounded", ImGuiTheme::ImGuiTheme_LightRounded, "")
        .value("so_dark_accent_blue", ImGuiTheme::ImGuiTheme_SoDark_AccentBlue, "")
        .value("so_dark_accent_yellow", ImGuiTheme::ImGuiTheme_SoDark_AccentYellow, "")
        .value("so_dark_accent_red", ImGuiTheme::ImGuiTheme_SoDark_AccentRed, "")
        .value("black_is_black", ImGuiTheme::ImGuiTheme_BlackIsBlack, "")
        .value("white_is_white", ImGuiTheme::ImGuiTheme_WhiteIsWhite, "")
        .value("count", ImGuiTheme::ImGuiTheme_Count, "");


    m.def("imgui_theme_name",
        ImGuiTheme::ImGuiTheme_Name,
        py::arg("theme"),
        pybind11::return_value_policy::reference);

    m.def("theme_to_style",
        ImGuiTheme::ThemeToStyle, py::arg("theme"));

    m.def("apply_theme",
        ImGuiTheme::ApplyTheme, py::arg("theme"));


    auto pyClassImGuiThemeTweaks =
        py::class_<ImGuiTheme::ImGuiThemeTweaks>
            (m, "ImGuiThemeTweaks", "")
        .def(py::init<>()) // implicit default constructor
        .def_readwrite("rounding", &ImGuiTheme::ImGuiThemeTweaks::Rounding, "Common rounding for widgets. If < 0, this is ignored.")
        .def_readwrite("rounding_scrollbar_ratio", &ImGuiTheme::ImGuiThemeTweaks::RoundingScrollbarRatio, "If rounding is applied, scrollbar rounding needs to be adjusted to be visually pleasing in conjunction with other widgets roundings. Only applied if Rounding > 0.)")
        .def_readwrite("alpha_multiplier", &ImGuiTheme::ImGuiThemeTweaks::AlphaMultiplier, "Change the alpha that will be applied to windows, popups, etc. If < 0, this is ignored.")
        .def_readwrite("hue", &ImGuiTheme::ImGuiThemeTweaks::Hue, "\n HSV Color tweaks\n\n Change the hue of all widgets (gray widgets will remain gray, since their saturation is zero). If < 0, this is ignored.")
        .def_readwrite("saturation_multiplier", &ImGuiTheme::ImGuiThemeTweaks::SaturationMultiplier, "Multiply the saturation of all widgets (gray widgets will remain gray, since their saturation is zero). If < 0, this is ignored.")
        .def_readwrite("value_multiplier_front", &ImGuiTheme::ImGuiThemeTweaks::ValueMultiplierFront, "Multiply the value of all front widgets. If < 0, this is ignored.")
        .def_readwrite("value_multiplier_bg", &ImGuiTheme::ImGuiThemeTweaks::ValueMultiplierBg, "Multiply the value of all backgrounds. If < 0, this is ignored.")
        ;


    auto pyClassImGuiTweakedTheme =
        py::class_<ImGuiTheme::ImGuiTweakedTheme>
            (m, "ImGuiTweakedTheme", "")
        .def(py::init<>()) // implicit default constructor
        .def_readwrite("theme", &ImGuiTheme::ImGuiTweakedTheme::Theme, "")
        .def_readwrite("tweaks", &ImGuiTheme::ImGuiTweakedTheme::Tweaks, "")
        ;


    m.def("tweaked_theme_theme_to_style",
        ImGuiTheme::TweakedThemeThemeToStyle, py::arg("tweaked_theme"));

    m.def("apply_tweaked_theme",
        ImGuiTheme::ApplyTweakedTheme, py::arg("tweaked_theme"));

    m.def("show_theme_tweak_gui",
        ImGuiTheme::ShowThemeTweakGui,
        py::arg("tweaked_theme"),
        "Show the theme selection listbox, the theme tweak widgets, as well as ImGui::ShowStyleEditor. Returns True if modified (Warning, when using ShowStyleEditor, no info about modification is transmitted)");

    m.def("so_dark",
        ImGuiTheme::SoDark, py::arg("hue"));

    m.def("shades_of_gray",
        ImGuiTheme::ShadesOfGray, py::arg("rounding") = 0.f, py::arg("value_multiplier_front") = 1.f, py::arg("value_multiplier_bg") = 1.f);

    m.def("darcula",
        ImGuiTheme::Darcula, py::arg("rounding") = 1.f, py::arg("hue") = -1.f, py::arg("saturation_multiplier") = 1.f, py::arg("value_multiplier_front") = 1.f, py::arg("value_multiplier_bg") = 1.f, py::arg("alpha_bg_transparency") = 1.f);


    py::enum_<HelloImGui::DefaultImGuiWindowType>(m, "DefaultImGuiWindowType", py::arithmetic(), "*\n@@md#DefaultImGuiWindowType\n\n__DefaultImGuiWindowType__ is an enum class that defines whether or not a full screen background window is provided.\n\n Values:\n  * _ProvideFullScreenWindow_: a full window is provided in the background\n  * _ProvideFullScreenDockSpace_: a full screen dockspace is provided in the background\n  * _NoDefaultWindow_: No default window is provided (except for ImGui's default \"debug\" window)\n\n@@md\n")
        .value("provide_full_screen_window", HelloImGui::DefaultImGuiWindowType::ProvideFullScreenWindow, "")
        .value("provide_full_screen_dock_space", HelloImGui::DefaultImGuiWindowType::ProvideFullScreenDockSpace, "")
        .value("no_default_window", HelloImGui::DefaultImGuiWindowType::NoDefaultWindow, "");


    auto pyClassImGuiWindowParams =
        py::class_<HelloImGui::ImGuiWindowParams>
            (m, "ImGuiWindowParams", "*\n@@md#ImGuiWindowParams\n\n__ImGuiWindowParams__ is a struct that defines the ImGui inner windows params\nThese settings affect the imgui inner windows inside the application window.\nIn order to change the application window settings, change the _AppWindowsParams_\n\n Members:\n\n  * `defaultImGuiWindowType`: _DefaultImGuiWindowType, default=ProvideFullScreenWindow_.\n      By default, a full window is provided in the background. You can still\n      add windows on top of it, since the Z-order of this background window is always behind\n\n  * `backgroundColor`: _ImVec4, default=ImVec4(0.45, 0.55, 0.60, 1.00)_.\n      This is the \"clearColor\", only visible is defaultImGuiWindowType is NoDefaultWindow.\n\n  * `showMenuBar`: _bool, default=false_.\n    Show Menu bar on top of imgui main window\n    You can customize the menu via `RunnerCallbacks.ShowMenus()`\n\n  * `showMenu_App`: _bool, default=true_.\n    If menu bar is shown, include or not the default app menu (with Quit button)\n\n  * `showMenu_View`: _bool, default=true_.\n    If menu bar is shown, include or not the default _View_ menu, that enables to change the layout and\n    set the docked windows and status bar visibility)\n\n  * `showStatusBar`: _bool, default=false_.\n    Flag that enable to show a Status bar at the bottom. You can customize the status bar\n    via RunnerCallbacks.ShowStatus()\n\n  * `showStatus_Fps`: _bool, default=true_. If set, display the FPS in the status bar.\n\n  * `configWindowsMoveFromTitleBarOnly`: _bool, default=true_.\n    Make windows only movable from the title bar\n\n  * `enableViewports`: _bool, default=false_. Enable multiple viewports (i.e multiple native windows)\n    If True, you can drag windows outside out the main window in order to put their content into new native windows.\n\n  * `tweakedTheme`: _string, default=\"ImGuiColorsDark\"_.\n    Change the ImGui theme. Several themes are available, you can query the list by calling\n    HelloImGui::AvailableThemes()\n@@md\n")
        .def(py::init<>()) // implicit default constructor
        .def_readwrite("default_imgui_window_type", &HelloImGui::ImGuiWindowParams::defaultImGuiWindowType, "")
        .def_readwrite("background_color", &HelloImGui::ImGuiWindowParams::backgroundColor, "")
        .def_readwrite("show_menu_bar", &HelloImGui::ImGuiWindowParams::showMenuBar, "")
        .def_readwrite("show_menu_app", &HelloImGui::ImGuiWindowParams::showMenu_App, "")
        .def_readwrite("show_menu_view", &HelloImGui::ImGuiWindowParams::showMenu_View, "")
        .def_readwrite("show_status_bar", &HelloImGui::ImGuiWindowParams::showStatusBar, "")
        .def_readwrite("show_status_fps", &HelloImGui::ImGuiWindowParams::showStatus_Fps, "")
        .def_readwrite("config_windows_move_from_title_bar_only", &HelloImGui::ImGuiWindowParams::configWindowsMoveFromTitleBarOnly, "")
        .def_readwrite("enable_viewports", &HelloImGui::ImGuiWindowParams::enableViewports, "")
        .def_readwrite("tweaked_theme", &HelloImGui::ImGuiWindowParams::tweakedTheme, "")
        ;


    m.def("load_font_ttf",
        HelloImGui::LoadFontTTF,
        py::arg("font_filename"), py::arg("font_size"), py::arg("use_full_glyph_range") = false, py::arg("config") = ImFontConfig(),
        pybind11::return_value_policy::reference);

    m.def("load_font_ttf_with_font_awesome_icons",
        HelloImGui::LoadFontTTF_WithFontAwesomeIcons,
        py::arg("font_filename"), py::arg("font_size"), py::arg("use_full_glyph_range") = false, py::arg("config_font") = ImFontConfig(), py::arg("config_icons") = ImFontConfig(),
        pybind11::return_value_policy::reference);

    m.def("merge_font_awesome_to_last_font",
        HelloImGui::MergeFontAwesomeToLastFont,
        py::arg("font_size"), py::arg("config") = ImFontConfig(),
        pybind11::return_value_policy::reference);


    auto pyClassMobileCallbacks =
        py::class_<HelloImGui::MobileCallbacks>
            (m, "MobileCallbacks", "*\n@@md#MobileCallbacks\n\n**MobileCallbacks** is a struct that contains callbacks that are called by the application\n when running under \"Android, iOS and WinRT\".\n These events are specific to mobile and embedded devices that have different requirements\n than your usual desktop application. These events must be handled quickly,\n since often the OS needs an immediate response and will terminate your process shortly\n after sending the event if you do not handle them apprpriately.\n\n Note: on mobile devices, it is not possible to \"Quit\" an application, it can only be put on Pause.\n\n * `OnDestroy`: _VoidFunction, default=empty_. The application is being terminated by the OS.\n * `OnLowMemory`: _VoidFunction, default=empty_. The application is low on memory, free memory if possible.\n * `OnPause`: _VoidFunction, default=empty_. The application is about to enter the background.\n * `OnResume`: _VoidFunction, default=empty_. The application is has come to foreground and is now interactive.\n\n Note: 'OnPause' and 'OnResume' are called twice consecutively under iOS (before and after entering background\n or foreground).\n\n@@md\n")
        .def(py::init<>()) // implicit default constructor
        .def_readwrite("on_destroy", &HelloImGui::MobileCallbacks::OnDestroy, "")
        .def_readwrite("on_low_memory", &HelloImGui::MobileCallbacks::OnLowMemory, "")
        .def_readwrite("on_pause", &HelloImGui::MobileCallbacks::OnPause, "")
        .def_readwrite("on_resume", &HelloImGui::MobileCallbacks::OnResume, "")
        ;


    auto pyClassRunnerCallbacks =
        py::class_<HelloImGui::RunnerCallbacks>
            (m, "RunnerCallbacks", "*\n @@md#RunnerCallbacks\n\n **RunnerCallbacks** is a struct that contains the callbacks that are called by the application\n\n _Members_\n\n* `ShowGui`: *VoidFunction, default=empty*.\n  Fill it with a function that will add your widgets.\n\n* `ShowMenus`: *VoidFunction, default=empty*.\n    A function that will render your menus. Fill it with a function that will add ImGui menus by calling:\n    _ImGui::BeginMenu(...) / ImGui::MenuItem(...) / ImGui::EndMenu()_\n\n    _Notes:_\n    * you do not need to call _ImGui::BeginMenuBar_ and _ImGui::EndMenuBar_\n    * Some default menus can be provided: see _ImGuiWindowParams_ options\n      (_showMenuBar, showMenu_App_QuitAbout, showMenu_View_)\n\n* `ShowStatus`: *VoidFunction, default=empty*.\n  A function that will add items to the status bar. Use small items (ImGui::Text for example),\n  since the height of the status is 30. Also, remember to call ImGui::SameLine() between items.\n\n* `PostInit`: *VoidFunction, default=empty*.\n    You can here add a function that will be called once after OpenGL and ImGui are inited\n\n* `BeforeExit`: *VoidFunction, default=empty*.\n    You can here add a function that will be called once before exiting (when OpenGL and ImGui are\n    still inited)\n\n* `AnyBackendEventCallback`: *AnyBackendCallback, default=empty*.\n  Callbacks for events from a specific backend. _Only implemented for SDL, where the event\n  will be of type 'SDL_Event *'_\n  This callback should return True if the event was handled and shall not be processed further.\n\n* `LoadAdditionalFonts`: *VoidFunction, default=_LoadDefaultFont_WithFontAwesome*.\n   A function that is called when fonts are ready to be loaded.\n   By default, _LoadDefaultFont_WithFontAwesome_ is called but you can copy-customize it.\n\n* `SetupImGuiConfig`: *VoidFunction, default=_ImGuiDefaultSettings::SetupDefaultImGuiConfig*.\n    If needed, change ImGui config via SetupImGuiConfig (enable docking, gamepad, etc)\n\n* `SetupImGuiStyle`: *VoidFunction, default=_ImGuiDefaultSettings::SetupDefaultImGuiConfig*.\n    If needed, setup your own style by providing your own SetupImGuiStyle callback\n\n\n* `mobileCallbacks`: *_MobileCallbacks_*. Callbacks that are called by the application\n    when running under \"Android, iOS and WinRT\".\nNotes:\n  * 'mobileCallbacks' is present only if the target device is a mobile device (iOS, Android).\n     Use `#ifdef HELLOIMGUI_MOBILEDEVICE` to detect this.\n  * These events are currently handled only with SDL backend.\n\n@@md\n")
        .def(py::init<>()) // implicit default constructor
        .def_readwrite("show_gui", &HelloImGui::RunnerCallbacks::ShowGui, "")
        .def_readwrite("show_menus", &HelloImGui::RunnerCallbacks::ShowMenus, "")
        .def_readwrite("show_status", &HelloImGui::RunnerCallbacks::ShowStatus, "")
        .def_readwrite("post_init", &HelloImGui::RunnerCallbacks::PostInit, "")
        .def_readwrite("before_exit", &HelloImGui::RunnerCallbacks::BeforeExit, "")
        .def_readwrite("any_backend_event_callback", &HelloImGui::RunnerCallbacks::AnyBackendEventCallback, "")
        .def_readwrite("load_additional_fonts", &HelloImGui::RunnerCallbacks::LoadAdditionalFonts, "")
        .def_readwrite("setup_imgui_config", &HelloImGui::RunnerCallbacks::SetupImGuiConfig, "")
        .def_readwrite("setup_imgui_style", &HelloImGui::RunnerCallbacks::SetupImGuiStyle, "")
        ;


    auto pyClassDockingSplit =
        py::class_<HelloImGui::DockingSplit>
            (m, "DockingSplit", "*\n@@md#DockingSplit\n\n**DockingSplit** is a struct that defines the way the docking splits should be applied on the screen\nin order to create new Dock Spaces. _DockingParams_ contains a _vector[DockingSplit]_,\nin order to partition the screen at your will.\n\n_Members:_\n\n* `initialDock`: _DockSpaceName (aka string)_\n\n    id of the space that should be split.\n    At the start, there is only one Dock Space named \"MainDockSpace\".\n    You should start by partitioning this space, in order to create a new dock space.\n\n* `newDock`: _DockSpaceName (aka string)_. id of the new dock space that will be created\n* `direction`: *ImGuiDir_ (enum with ImGuiDir_Down, ImGuiDir_Down, ImGuiDir_Left, ImGuiDir_Right)*.\nDirection where this dock space should be created\n* `ratio`: _float, default=0.25_. Ratio of the initialDock size that should be used by the new dock space\n\n@@md\n")
        .def(py::init<>()) // implicit default constructor
        .def_readwrite("initial_dock", &HelloImGui::DockingSplit::initialDock, "")
        .def_readwrite("new_dock", &HelloImGui::DockingSplit::newDock, "")
        .def_readwrite("direction", &HelloImGui::DockingSplit::direction, "")
        .def_readwrite("ratio", &HelloImGui::DockingSplit::ratio, "")
        ;


    auto pyClassDockableWindow =
        py::class_<HelloImGui::DockableWindow>
            (m, "DockableWindow", "*\n@@md#DockableWindow\n\n**DockableWindow** is a struct that represents a window that can be docked.\n\n_Members:_\n\n* `label`: _string_. Title of the window.\n* `dockSpaceName`: _DockSpaceName (aka string)_. Id of the dock space where this window\n   should initialy be placed\n* `GuiFunction`: _VoidFuntion_. Any function that will render this window's Gui.\n* `isVisible`: _bool, default=true_. Flag that indicates whether this window is visible or not.\n* `canBeClosed`: _bool, default=true_. Flag that indicates whether the user can close this window.\n* `callBeginEnd`: _bool, default=true_. Flag that indicates whether ImGui::Begin and ImGui::End\n   calls should be added automatically (with the given \"label\"). Set to False if you want to call\n   ImGui::Begin/End yourself\n* `includeInViewMenu`: _bool, default=true_. Flag that indicates whether this window should be mentioned\n   in the view menu.\n* `imGuiWindowFlags`: _ImGuiWindowFlags, default=0_. Window flags, see enum ImGuiWindowFlags_\n* `windowSize`: _ImVec2, default=(0., 0.) (i.e let the app decide)_. Window size (unused if docked)\n* `windowSizeCondition`: _ImGuiCond, default=ImGuiCond_FirstUseEver_. When to apply the window size.\n* `windowPos`: _ImVec2, default=(0., 0.) (i.e let the app decide)_. Window position (unused if docked)\n* `windowPosCondition`: _ImGuiCond, default=ImGuiCond_FirstUseEver_. When to apply the window position.\n* `focusWindowAtNextFrame`: _bool, default = false_. If set to True this window will be focused at the next frame.\n\n@@md\n*")
        .def(py::init<>()) // implicit default constructor
        .def_readwrite("label", &HelloImGui::DockableWindow::label, "")
        .def_readwrite("dock_space_name", &HelloImGui::DockableWindow::dockSpaceName, "")
        .def_readwrite("gui_function", &HelloImGui::DockableWindow::GuiFunction, "")
        .def_readwrite("is_visible", &HelloImGui::DockableWindow::isVisible, "")
        .def_readwrite("can_be_closed", &HelloImGui::DockableWindow::canBeClosed, "")
        .def_readwrite("call_begin_end", &HelloImGui::DockableWindow::callBeginEnd, "")
        .def_readwrite("include_in_view_menu", &HelloImGui::DockableWindow::includeInViewMenu, "")
        .def_readwrite("imgui_window_flags", &HelloImGui::DockableWindow::imGuiWindowFlags, "")
        .def_readwrite("window_size", &HelloImGui::DockableWindow::windowSize, "")
        .def_readwrite("window_size_condition", &HelloImGui::DockableWindow::windowSizeCondition, "")
        .def_readwrite("window_position", &HelloImGui::DockableWindow::windowPosition, "")
        .def_readwrite("window_position_condition", &HelloImGui::DockableWindow::windowPositionCondition, "")
        .def_readwrite("focus_window_at_next_frame", &HelloImGui::DockableWindow::focusWindowAtNextFrame, "")
        ;


    auto pyClassDockingParams =
        py::class_<HelloImGui::DockingParams>
            (m, "DockingParams", "*\n@@md#DockingParams\n\n**DockingParams** contains all the settings concerning the docking,\n together _with the Gui functions for the docked windows_.\n\n _Members:_\n\n* `dockingSplits`: _vector[DockingSplit]_.\n  Defines the way docking splits should be applied on the screen in order to create new Dock Spaces\n* `dockableWindows`: _vector[DockableWindow]_.\n  List of the dockable windows, together with their Gui code\n* `resetUserDockLayout`: _bool, default=true_.\n  Reset user layout at application startup\n\n _Helpers:_\n\n * `DockableWindow * dockableWindowOfName(const std::string & name)`: returns a pointer to a dockable window\n * `None focusDockableWindow(const std::string& name)`: will focus a dockable window\n\n@@md\n")
        .def(py::init<>()) // implicit default constructor
        .def_readwrite("docking_splits", &HelloImGui::DockingParams::dockingSplits, "")
        .def_readwrite("dockable_windows", &HelloImGui::DockingParams::dockableWindows, "")
        .def_readwrite("reset_user_dock_layout", &HelloImGui::DockingParams::resetUserDockLayout, "")
        .def_readwrite("was_dock_layout_applied", &HelloImGui::DockingParams::wasDockLayoutApplied, "wasDockLayoutApplied is an internal variable")
        .def("dockable_window_of_name",
            &HelloImGui::DockingParams::dockableWindowOfName,
            py::arg("name"),
            pybind11::return_value_policy::reference)
        .def("focus_dockable_window",
            &HelloImGui::DockingParams::focusDockableWindow, py::arg("window_name"))
        ;


    auto pyClassBackendPointers =
        py::class_<HelloImGui::BackendPointers>
            (m, "BackendPointers", "*\n @@md#BackendPointers\n\n**BackendPointers** is a struct that contains optional pointers to the backend implementations (for SDL and GLFW).\n\nThese pointers will be filled when the application starts, and you can use them to customize\nyour application behavior using the selected backend.\n\n Members:\n* `glfwWindow`: _void *, default=nullptr_. Pointer to the main GLFW window (of type `GLFWwindow*`).\n  Only filled if the backend is GLFW.\n* `sdlWindow`: _void *, default=nullptr_. Pointer to the main SDL window (of type `SDL_Window*`).\n  Only filled if the backend is SDL (or emscripten + sdl)\n* `sdlGlContext`: _void *, default=nullptr_. Pointer to SDL's GlContext (of type `SDL_GLContext`).\n  Only filled if the backend is SDL (or emscripten + sdl)\n\n@@md\n")
        .def(py::init<>()) // implicit default constructor
        .def_readwrite("glfw_window", &HelloImGui::BackendPointers::glfwWindow, "")
        .def_readwrite("sdl_window", &HelloImGui::BackendPointers::sdlWindow, "")
        .def_readwrite("sdl_gl_context", &HelloImGui::BackendPointers::sdlGlContext, "")
        ;


    py::enum_<HelloImGui::BackendType>(m, "BackendType", py::arithmetic(), "")
        .value("first_available", HelloImGui::BackendType::FirstAvailable, "")
        .value("sdl", HelloImGui::BackendType::Sdl, "")
        .value("glfw", HelloImGui::BackendType::Glfw, "")
        .value("qt", HelloImGui::BackendType::Qt, "");


    auto pyClassRunnerParams =
        py::class_<HelloImGui::RunnerParams>
            (m, "RunnerParams", "*\n @@md#RunnerParams\n\n**RunnerParams** is a struct that contains all the settings and callbacks needed to run an application.\n\n Members:\n* `callbacks`: _see [runner_callbacks.h](runner_callbacks.h)_.\n    callbacks.ShowGui() will render the gui, ShowMenus() will show the menus, etc.\n* `appWindowParams`: _see [app_window_params.h](app_window_params.h)_.\n    application Window Params (position, size, title)\n* `imGuiWindowParams`: _see [imgui_window_params.h](imgui_window_params.h)_.\n    imgui window params (use docking, showMenuBar, ProvideFullScreenWindow, etc)\n* `dockingParams`: _see [docking_params.h](docking_params.h)_.\n    dockable windows content and layout\n* `backendPointers`: _see [backend_pointers.h](backend_pointers.h)_.\n   A struct that contains optional pointers to the backend implementations. These pointers will be filled\n   when the application starts\n* `backendType`: _enum BackendType, default=BackendType::FirstAvailable_\n  Select the wanted backend type between `Sdl`, `Glfw` and `Qt`. Only useful when multiple backend are compiled\n  and available.\n* `appShallExit`: _bool, default=false_.\n   Will be set to True by the app when exiting.\n   _Note: 'appShallExit' has no effect on Mobile Devices (iOS, Android) and under emscripten, since these apps\n   shall not exit._\n* `fpsIdle`: _float, default=10_.\n  ImGui applications can consume a lot of CPU, since they update the screen very frequently.\n  In order to reduce the CPU usage, the FPS is reduced when no user interaction is detected.\n  This is ok most of the time but if you are displaying animated widgets (for example a live video),\n  you may want to ask for a faster refresh: either increase fpsIdle, or set it to 0 for maximum refresh speed\n  (you can change this value during the execution depending on your application refresh needs)\n* `emscripten_fps`: _int, default = 0_.\n  Set the application refresh rate (only used on emscripten: 0 stands for \"let the app or the browser decide\")\n@@md\n")
        .def(py::init<>()) // implicit default constructor
        .def_readwrite("callbacks", &HelloImGui::RunnerParams::callbacks, "")
        .def_readwrite("app_window_params", &HelloImGui::RunnerParams::appWindowParams, "")
        .def_readwrite("imgui_window_params", &HelloImGui::RunnerParams::imGuiWindowParams, "")
        .def_readwrite("docking_params", &HelloImGui::RunnerParams::dockingParams, "")
        .def_readwrite("backend_pointers", &HelloImGui::RunnerParams::backendPointers, "")
        .def_readwrite("backend_type", &HelloImGui::RunnerParams::backendType, "")
        .def_readwrite("app_shall_exit", &HelloImGui::RunnerParams::appShallExit, "")
        .def_readwrite("fps_idle", &HelloImGui::RunnerParams::fpsIdle, "")
        .def_readwrite("emscripten_fps", &HelloImGui::RunnerParams::emscripten_fps, "")
        ;


    auto pyClassSimpleRunnerParams =
        py::class_<HelloImGui::SimpleRunnerParams>
            (m, "SimpleRunnerParams", "*\n @@md#SimpleRunnerParams\n\n**RunnerParams** is a struct that contains simpler params adapted for simple uses\n\n Members:\n* `guiFunction`: _VoidFunction_.\n   Function that renders the Gui.\n* `windowTitle`: _string, default=\"\"_.\n   Title of the application window\n* `windowSizeAuto`: _bool, default=false_.\n   If True, the size of the window will be computed from its widgets.\n* `windowRestorePreviousGeometry`: _bool, default=true_.\n   If True, restore the size and position of the window between runs.\n* `windowSize`: _ScreenSize, default={800, 600}_.\n   Size of the window\n* `fpsIdle`: _float, default=10_.\n   FPS of the application when idle (set to 0 for full speed).\n@@md\n")
        .def(py::init<>()) // implicit default constructor
        .def_readwrite("gui_function", &HelloImGui::SimpleRunnerParams::guiFunction, "")
        .def_readwrite("window_title", &HelloImGui::SimpleRunnerParams::windowTitle, "")
        .def_readwrite("window_size_auto", &HelloImGui::SimpleRunnerParams::windowSizeAuto, "")
        .def_readwrite("window_restore_previous_geometry", &HelloImGui::SimpleRunnerParams::windowRestorePreviousGeometry, "")
        .def_readwrite("window_size", &HelloImGui::SimpleRunnerParams::windowSize, "")
        .def_readwrite("fps_idle", &HelloImGui::SimpleRunnerParams::fpsIdle, "")
        .def("to_runner_params",
            &HelloImGui::SimpleRunnerParams::ToRunnerParams)
        ;


    py::enum_<HelloImGui::LogLevel>(m, "LogLevel", py::arithmetic(), "")
        .value("debug", HelloImGui::LogLevel::Debug, "")
        .value("info", HelloImGui::LogLevel::Info, "")
        .value("warning", HelloImGui::LogLevel::Warning, "")
        .value("error", HelloImGui::LogLevel::Error, "");


    m.def("log",
        [](HelloImGui::LogLevel level, const char * const format)
        {
            auto Log_adapt_variadic_format = [](HelloImGui::LogLevel level, const char * const format)
            {
                HelloImGui::Log(level, "%s", format);
            };

            Log_adapt_variadic_format(level, format);
        },     py::arg("level"), py::arg("format"));

    m.def("log_clear",
        HelloImGui::LogClear);

    m.def("log_gui",
        HelloImGui::LogGui);


    m.def("run",
        py::overload_cast<HelloImGui::RunnerParams &>(HelloImGui::Run), py::arg("runner_params"));

    m.def("run",
        py::overload_cast<const HelloImGui::SimpleRunnerParams &>(HelloImGui::Run), py::arg("simple_params"));

    m.def("get_runner_params",
        HelloImGui::GetRunnerParams, pybind11::return_value_policy::reference);

    { // <namespace ImGuiDefaultSettings>
        py::module_ pyNsImGuiDefaultSettings = m.def_submodule("ImGuiDefaultSettings", "namespace ImGuiDefaultSettings");
        pyNsImGuiDefaultSettings.def("load_default_font_with_font_awesome_icons",
            HelloImGui::ImGuiDefaultSettings::LoadDefaultFont_WithFontAwesomeIcons);

        pyNsImGuiDefaultSettings.def("setup_default_imgui_config",
            HelloImGui::ImGuiDefaultSettings::SetupDefaultImGuiConfig);

        pyNsImGuiDefaultSettings.def("setup_default_imgui_style",
            HelloImGui::ImGuiDefaultSettings::SetupDefaultImGuiStyle);
    } // </namespace ImGuiDefaultSettings>
    ////////////////////    </generated_from:hello_imgui_amalgamation.h>    ////////////////////

    // </litgen_pydef> // Autogenerated code end
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE END !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}
