// Part of ImGui Bundle - MIT License - Copyright (c) 2022-2023 Pascal Thomet - https://github.com/pthom/imgui_bundle
#include <pybind11/pybind11.h>

#include "imgui_tex_inspect/imgui_tex_inspect_internal.h"
#include "imgui_tex_inspect/imgui_tex_inspect.h"
#include "imgui_tex_inspect/imgui_tex_inspect_demo.h"


namespace py = pybind11;

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// <litgen_glue_code>  // Autogenerated code below! Do not edit!

// </litgen_glue_code> // Autogenerated code end
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE END !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


PYBIND11_MAKE_OPAQUE(ImGuiTexInspect::Context);


void py_init_module_imgui_tex_inspect(py::module& m)
{
    using namespace ImGuiTexInspect;

    m.def("create_context", []() {
        Context* ctx = ImGuiTexInspect::CreateContext();
        uintptr_t address = (uintptr_t)ctx;
        return address;
    });

    m.def("destroy_context", [](uintptr_t address) {
        Context* ctx = (Context *) address;
        ImGuiTexInspect::DestroyContext(ctx);
    });

    m.def("set_current_context", [](uintptr_t address) {
        Context* ctx = (Context *) address;
        ImGuiTexInspect::SetCurrentContext(ctx);
    });

    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // <litgen_pydef> // Autogenerated code below! Do not edit!
    ////////////////////    <generated_from:imgui_tex_inspect.h>    ////////////////////
    m.def("init",
        ImGuiTexInspect::Init);

    m.def("shutdown",
        ImGuiTexInspect::Shutdown);


    py::enum_<ImGuiTexInspect::InspectorAlphaMode>(m, "InspectorAlphaMode", py::arithmetic(), "")
        .value("im_gui", ImGuiTexInspect::InspectorAlphaMode_ImGui, "Alpha is transparency so you see the ImGui panel background behind image")
        .value("black", ImGuiTexInspect::InspectorAlphaMode_Black, "Alpha is used to blend over a black background")
        .value("white", ImGuiTexInspect::InspectorAlphaMode_White, "Alpha is used to blend over a white background")
        .value("custom_color", ImGuiTexInspect::InspectorAlphaMode_CustomColor, "Alpha is used to blend over a custom colour.");


    py::enum_<ImGuiTexInspect::InspectorFlags_>(m, "InspectorFlags_", py::arithmetic(), "")
        .value("show_wrap", ImGuiTexInspect::InspectorFlags_ShowWrap, "Draw beyong the [0,1] uv range. What you see will depend on API")
        .value("no_force_filter_nearest", ImGuiTexInspect::InspectorFlags_NoForceFilterNearest, "Normally we force nearest neighbour sampling when zoomed in. Set to disable this.")
        .value("no_grid", ImGuiTexInspect::InspectorFlags_NoGrid, "By default a grid is shown at high zoom levels")
        .value("no_tooltip", ImGuiTexInspect::InspectorFlags_NoTooltip, "Disable tooltip on hover")
        .value("fill_horizontal", ImGuiTexInspect::InspectorFlags_FillHorizontal, "Scale to fill available space horizontally")
        .value("fill_vertical", ImGuiTexInspect::InspectorFlags_FillVertical, "Scale to fill available space vertically")
        .value("no_auto_read_texture", ImGuiTexInspect::InspectorFlags_NoAutoReadTexture, "By default texture data is read to CPU every frame for tooltip and annotations")
        .value("flip_x", ImGuiTexInspect::InspectorFlags_FlipX, "Horizontally flip the way the texture is displayed")
        .value("flip_y", ImGuiTexInspect::InspectorFlags_FlipY, "Vertically flip the way the texture is displayed");


    auto pyClassSizeIncludingBorder =
        py::class_<ImGuiTexInspect::SizeIncludingBorder>
            (m, "SizeIncludingBorder", "")
        .def_readwrite("size", &SizeIncludingBorder::Size, "")
        .def(py::init<ImVec2>(),
            py::arg("size"))
        ;


    auto pyClassSizeExcludingBorder =
        py::class_<ImGuiTexInspect::SizeExcludingBorder>
            (m, "SizeExcludingBorder", "")
        .def_readwrite("size", &SizeExcludingBorder::size, "")
        .def(py::init<ImVec2>(),
            py::arg("size"))
        ;


    m.def("begin_inspector_panel",
        py::overload_cast<const char *, ImTextureID, ImVec2, InspectorFlags>(ImGuiTexInspect::BeginInspectorPanel), py::arg("name"), py::arg("param_1"), py::arg("texture_size"), py::arg("flags") = 0);

    m.def("begin_inspector_panel",
        py::overload_cast<const char *, ImTextureID, ImVec2, InspectorFlags, ImGuiTexInspect::SizeIncludingBorder>(ImGuiTexInspect::BeginInspectorPanel), py::arg("name"), py::arg("param_1"), py::arg("texture_size"), py::arg("flags"), py::arg("size"));

    m.def("begin_inspector_panel",
        py::overload_cast<const char *, ImTextureID, ImVec2, InspectorFlags, ImGuiTexInspect::SizeExcludingBorder>(ImGuiTexInspect::BeginInspectorPanel), py::arg("name"), py::arg("param_1"), py::arg("texture_size"), py::arg("flags"), py::arg("size"));

    m.def("end_inspector_panel",
        ImGuiTexInspect::EndInspectorPanel, " EndInspectorPanel\n * Always call after BeginInspectorPanel and after you have drawn any required annotations");

    m.def("release_inspector_data",
        ImGuiTexInspect::ReleaseInspectorData,
        py::arg("id"),
        " ReleaseInspectorData\n * ImGuiTexInspect keeps texture data cached in memory.  If you know you won't\n * be displaying a particular panel for a while you can call this to release\n * the memory. It won't be allocated again until next time you call\n * BeginInspectorPanel.  If id is None then the current (most recent) inspector\n * will be affected.  Unless you have a lot of different Inspector instances\n * you can probably not worry about this. Call CurrentInspector_GetID to get\n * the ID of an inspector.\n");

    m.def("current_inspector_set_alpha_mode",
        ImGuiTexInspect::CurrentInspector_SetAlphaMode, py::arg("param_0"));

    m.def("current_inspector_set_flags",
        ImGuiTexInspect::CurrentInspector_SetFlags, py::arg("to_set"), py::arg("to_clear") = 0);

    m.def("current_inspector_clear_flags",
        ImGuiTexInspect::CurrentInspector_ClearFlags, py::arg("to_clear"));

    m.def("current_inspector_set_grid_color",
        ImGuiTexInspect::CurrentInspector_SetGridColor, py::arg("color"));

    m.def("current_inspector_set_max_annotations",
        ImGuiTexInspect::CurrentInspector_SetMaxAnnotations, py::arg("max_annotations"));

    m.def("current_inspector_invalidate_texture_cache",
        ImGuiTexInspect::CurrentInspector_InvalidateTextureCache, " CurrentInspector_InvalidateTextureCache\n * If using the InspectorFlags_NoAutoReadTexture flag then call this to\n * indicate your texture has changed context.\n");

    m.def("current_inspector_set_custom_background_color",
        py::overload_cast<ImVec4>(ImGuiTexInspect::CurrentInspector_SetCustomBackgroundColor), py::arg("color"));

    m.def("current_inspector_set_custom_background_color",
        py::overload_cast<ImU32>(ImGuiTexInspect::CurrentInspector_SetCustomBackgroundColor), py::arg("color"));

    m.def("current_inspector_get_id",
        ImGuiTexInspect::CurrentInspector_GetID, " CurrentInspector_GetID\n * Get the ID of the current inspector.  Currently only used for calling\n * ReleaseInspectorData.\n");

    m.def("draw_color_matrix_editor",
        ImGuiTexInspect::DrawColorMatrixEditor, "ColorMatrix editor.  See comments on ColorMatrix below.");

    m.def("draw_grid_editor",
        ImGuiTexInspect::DrawGridEditor, "Grid editor.  Enable/Disable grid. Set Grid Color.");

    m.def("draw_color_channel_selector",
        ImGuiTexInspect::DrawColorChannelSelector, "For toggling R,G,B channels");

    m.def("draw_alpha_mode_selector",
        ImGuiTexInspect::DrawAlphaModeSelector, "A combo box for selecting the alpha mode");

    m.def("set_zoom_rate",
        ImGuiTexInspect::SetZoomRate,
        py::arg("factor"),
        "-------------------------------------------------------------------------\n [SECTION] CONTEXT-WIDE SETTINGS\n-------------------------------------------------------------------------\n/* SetZoomRate\n * factor should be greater than 1.  A value of 1.5 means one mouse wheel\n * scroll will increase zoom level by 50%. The factor used for zooming out is\n * 1/factor. */");

    m.def("draw_annotation_line",
        ImGuiTexInspect::DrawAnnotationLine,
        py::arg("draw_list"), py::arg("from_texel"), py::arg("to_texel"), py::arg("texels_to_pixels"), py::arg("color"),
        " DrawAnnotationLine\n * Convenience function to add a line to draw list using texel coordinates.\n");


    auto pyClassValueText =
        py::class_<ImGuiTexInspect::ValueText>
            (m, "ValueText", " ValueText\n * An annoation class that draws text inside each texel when zoom level is high enough for it to fit.\n * The text shows the value of the texel. E.g. \"R:255, G: 128, B:0, A:255\"\n");

    { // inner classes & enums of ValueText
        py::enum_<ImGuiTexInspect::ValueText::Format>(pyClassValueText, "Format", py::arithmetic(), "")
            .value("hex_string", ImGuiTexInspect::ValueText::HexString, "E.g.  #EF97B9FF")
            .value("bytes_hex", ImGuiTexInspect::ValueText::BytesHex, "E.g.  R:#EF G:#97 B:#B9 A:#FF  (split over 4 lines)")
            .value("bytes_dec", ImGuiTexInspect::ValueText::BytesDec, "E.g.  R:239 G: 151 B:185 A:255  (split over 4 lines)")
            .value("floats", ImGuiTexInspect::ValueText::Floats, "E.g.  0.937 0.592 0.725 1.000 (split over 4 lines)");
    } // end of inner classes & enums of ValueText

    pyClassValueText
        .def(py::init<ImGuiTexInspect::ValueText::Format>(),
            py::arg("format") = ImGuiTexInspect::ValueText::HexString)
        .def("draw_annotation",
            &ValueText::DrawAnnotation, py::arg("draw_list"), py::arg("texel"), py::arg("texels_to_pixels"), py::arg("value"))
        ;


    auto pyClassArrow =
        py::class_<ImGuiTexInspect::Arrow>
            (m, "Arrow", " Arrow\n * An annotation class that draws an arrow inside each texel when zoom level is\n * high enough. The direction and length of the arrow are determined by texel\n * values.\n * The X and Y components of the arrow is determined by the VectorIndex_x, and\n * VectorIndex_y channels of the texel value.  Examples:\n\n * VectorIndex_x = 0,  VectorIndex_y = 1  means  X component is red and Y component is green\n * VectorIndex_x = 1,  VectorIndex_y = 2  means  X component is green and Y component is blue\n * VectorIndex_x = 0,  VectorIndex_y = 3  means  X component is red and Y component is alpha\n *\n * ZeroPoint is the texel value which corresponds to a zero length vector. E.g.\n * ZeroPoint = (0.5, 0.5) means (0.5, 0.5) will be drawn as a zero length arrow\n *\n * All public properties can be directly manipulated.  There are also presets that can be set\n * by calling UsePreset.\n\n");

    { // inner classes & enums of Arrow
        py::enum_<ImGuiTexInspect::Arrow::Preset>(pyClassArrow, "Preset", py::arithmetic(), "")
            .value("normal_map", ImGuiTexInspect::Arrow::NormalMap, "For normal maps. I.e. Arrow is in (R,G) channels.  128, 128 is zero point")
            .value("normalized_float", ImGuiTexInspect::Arrow::NormalizedFloat, "Arrow in (R,G) channels. 0,0 is zero point, (1,0) will draw an arrow exactly to");
    } // end of inner classes & enums of Arrow

    pyClassArrow
        .def_readwrite("vector_index_x", &Arrow::VectorIndex_x, "")
        .def_readwrite("vector_index_y", &Arrow::VectorIndex_y, "")
        .def_readwrite("line_scale", &Arrow::LineScale, "")
        .def_readwrite("zero_point", &Arrow::ZeroPoint, "")
        .def(py::init<int, int, ImVec2>(),
            py::arg("x_vector_index") = 0, py::arg("y_vector_index") = 1, py::arg("line_scale") = ImVec2(1, 1))
        .def("use_preset",
            &Arrow::UsePreset, py::arg("param_0"))
        .def("draw_annotation",
            &Arrow::DrawAnnotation, py::arg("draw_list"), py::arg("texel"), py::arg("texels_to_pixels"), py::arg("value"))
        ;


    auto pyClassTransform2D =
        py::class_<ImGuiTexInspect::Transform2D>
            (m, "Transform2D", "")
        .def(py::init<>([](
        ImVec2 Scale = ImVec2(), ImVec2 Translate = ImVec2())
        {
            auto r = std::make_unique<Transform2D>();
            r->Scale = Scale;
            r->Translate = Translate;
            return r;
        })
        , py::arg("scale") = ImVec2(), py::arg("translate") = ImVec2()
        )
        .def_readwrite("scale", &Transform2D::Scale, "")
        .def_readwrite("translate", &Transform2D::Translate, "")
        .def("__mul__",
            &Transform2D::operator*,
            py::arg("rhs"),
            "Transform a vector by this transform.  Scale is applied first")
        .def("inverse",
            &Transform2D::Inverse, "Return an inverse transform such that transform.Inverse() * transform * vector == vector")
        ;
    ////////////////////    </generated_from:imgui_tex_inspect.h>    ////////////////////


    ////////////////////    <generated_from:imgui_tex_inspect_demo.h>    ////////////////////
    auto pyClassTexture =
        py::class_<ImGuiTexInspect::Texture>
            (m, "Texture", "")
        .def(py::init<>([](
        ImTextureID texture = ImTextureID(), ImVec2 size = ImVec2())
        {
            auto r = std::make_unique<Texture>();
            r->texture = texture;
            r->size = size;
            return r;
        })
        , py::arg("texture") = ImTextureID(), py::arg("size") = ImVec2()
        )
        .def_readwrite("texture", &Texture::texture, "")
        .def_readwrite("size", &Texture::size, "")
        ;


    m.def("show_demo_window",
        ImGuiTexInspect::ShowDemoWindow);
    ////////////////////    </generated_from:imgui_tex_inspect_demo.h>    ////////////////////

    // </litgen_pydef> // Autogenerated code end
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE END !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}
