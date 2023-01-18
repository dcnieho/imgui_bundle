// Part of ImGui Bundle - MIT License - Copyright (c) 2022-2023 Pascal Thomet - https://github.com/pthom/imgui_bundle
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>
#include <pybind11/numpy.h>

#include "ImGuiColorTextEdit/TextEditor.h"

namespace py = pybind11;

typedef uint8_t Char;

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// <litgen_glue_code>  // Autogenerated code below! Do not edit!

// </litgen_glue_code> // Autogenerated code end
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE END !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


void py_init_module_imgui_color_text_edit(py::module& m)
{
    // You can add any code here
    using PaletteIndex = TextEditor::PaletteIndex;
    using Keywords = TextEditor::Keywords;
    using Identifiers = TextEditor::Identifiers;
    using TokenRegexStrings = TextEditor::LanguageDefinition::TokenRegexStrings;

    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // <litgen_pydef> // Autogenerated code below! Do not edit!
    ////////////////////    <generated_from:TextEditor.h>    ////////////////////
    auto pyClassTextEditor =
        py::class_<TextEditor>
            (m, "TextEditor", "");

    { // inner classes & enums of TextEditor
        py::enum_<TextEditor::PaletteIndex>(pyClassTextEditor, "PaletteIndex", py::arithmetic(), "")
            .value("default", TextEditor::PaletteIndex::Default, "")
            .value("keyword", TextEditor::PaletteIndex::Keyword, "")
            .value("number", TextEditor::PaletteIndex::Number, "")
            .value("string", TextEditor::PaletteIndex::String, "")
            .value("char_literal", TextEditor::PaletteIndex::CharLiteral, "")
            .value("punctuation", TextEditor::PaletteIndex::Punctuation, "")
            .value("preprocessor", TextEditor::PaletteIndex::Preprocessor, "")
            .value("identifier", TextEditor::PaletteIndex::Identifier, "")
            .value("known_identifier", TextEditor::PaletteIndex::KnownIdentifier, "")
            .value("preproc_identifier", TextEditor::PaletteIndex::PreprocIdentifier, "")
            .value("comment", TextEditor::PaletteIndex::Comment, "")
            .value("multi_line_comment", TextEditor::PaletteIndex::MultiLineComment, "")
            .value("background", TextEditor::PaletteIndex::Background, "")
            .value("cursor", TextEditor::PaletteIndex::Cursor, "")
            .value("selection", TextEditor::PaletteIndex::Selection, "")
            .value("error_marker", TextEditor::PaletteIndex::ErrorMarker, "")
            .value("breakpoint", TextEditor::PaletteIndex::Breakpoint, "")
            .value("line_number", TextEditor::PaletteIndex::LineNumber, "")
            .value("current_line_fill", TextEditor::PaletteIndex::CurrentLineFill, "")
            .value("current_line_fill_inactive", TextEditor::PaletteIndex::CurrentLineFillInactive, "")
            .value("current_line_edge", TextEditor::PaletteIndex::CurrentLineEdge, "")
            .value("max", TextEditor::PaletteIndex::Max, "");
        py::enum_<TextEditor::SelectionMode>(pyClassTextEditor, "SelectionMode", py::arithmetic(), "")
            .value("normal", TextEditor::SelectionMode::Normal, "")
            .value("word", TextEditor::SelectionMode::Word, "")
            .value("line", TextEditor::SelectionMode::Line, "");
        auto pyClassTextEditor_ClassBreakpoint =
            py::class_<TextEditor::Breakpoint>
                (pyClassTextEditor, "Breakpoint", "")
            .def_readwrite("m_line", &TextEditor::Breakpoint::mLine, "")
            .def_readwrite("m_enabled", &TextEditor::Breakpoint::mEnabled, "")
            .def_readwrite("m_condition", &TextEditor::Breakpoint::mCondition, "")
            .def(py::init<>())
            ;
        auto pyClassTextEditor_ClassCoordinates =
            py::class_<TextEditor::Coordinates>
                (pyClassTextEditor, "Coordinates", " Represents a character coordinate from the user's point of view,\n i. e. consider an uniform grid (assuming fixed-width font) on the\n screen as it is rendered, and each cell has its own coordinate, starting from 0.\n Tabs are counted as [1..mTabSize] count empty spaces, depending on\n how many space is necessary to reach the next tab stop.\n For example, coordinate (1, 5) represents the character 'B' in a line \"\tABC\", when mTabSize = 4,\n because it is rendered as \"    ABC\" on the screen.")
            .def_readwrite("m_line", &TextEditor::Coordinates::mLine, "")
            .def_readwrite("m_column", &TextEditor::Coordinates::mColumn, "")
            .def(py::init<>())
            .def(py::init<int, int>(),
                py::arg("a_line"), py::arg("a_column"))
            .def_static("invalid",
                &TextEditor::Coordinates::Invalid)
            .def("__eq__",
                &TextEditor::Coordinates::operator==, py::arg("o"))
            .def("__ne__",
                &TextEditor::Coordinates::operator!=, py::arg("o"))
            .def("__lt__",
                &TextEditor::Coordinates::operator<, py::arg("o"))
            .def("__gt__",
                &TextEditor::Coordinates::operator>, py::arg("o"))
            .def("__le__",
                &TextEditor::Coordinates::operator<=, py::arg("o"))
            .def("__ge__",
                &TextEditor::Coordinates::operator>=, py::arg("o"))
            ;
        auto pyClassTextEditor_ClassIdentifier =
            py::class_<TextEditor::Identifier>
                (pyClassTextEditor, "Identifier", "")
            .def(py::init<>([](
            TextEditor::Coordinates mLocation = TextEditor::Coordinates(), std::string mDeclaration = std::string())
            {
                auto r = std::make_unique<TextEditor::Identifier>();
                r->mLocation = mLocation;
                r->mDeclaration = mDeclaration;
                return r;
            })
            , py::arg("m_location") = TextEditor::Coordinates(), py::arg("m_declaration") = std::string()
            )
            .def_readwrite("m_location", &TextEditor::Identifier::mLocation, "")
            .def_readwrite("m_declaration", &TextEditor::Identifier::mDeclaration, "")
            ;
        auto pyClassTextEditor_ClassGlyph =
            py::class_<TextEditor::Glyph>
                (pyClassTextEditor, "Glyph", "")
            .def_readwrite("m_char", &TextEditor::Glyph::mChar, "")
            .def_readwrite("m_color_index", &TextEditor::Glyph::mColorIndex, "")
            .def(py::init<Char, TextEditor::PaletteIndex>(),
                py::arg("a_char"), py::arg("a_color_index"))
            ;
        auto pyClassTextEditor_ClassLanguageDefinition =
            py::class_<TextEditor::LanguageDefinition>
                (pyClassTextEditor, "LanguageDefinition", "")
            .def_readwrite("m_name", &TextEditor::LanguageDefinition::mName, "")
            .def_readwrite("m_keywords", &TextEditor::LanguageDefinition::mKeywords, "")
            .def_readwrite("m_identifiers", &TextEditor::LanguageDefinition::mIdentifiers, "")
            .def_readwrite("m_preproc_identifiers", &TextEditor::LanguageDefinition::mPreprocIdentifiers, "")
            .def_readwrite("m_comment_start", &TextEditor::LanguageDefinition::mCommentStart, "")
            .def_readwrite("m_comment_end", &TextEditor::LanguageDefinition::mCommentEnd, "")
            .def_readwrite("m_single_line_comment", &TextEditor::LanguageDefinition::mSingleLineComment, "")
            .def_readwrite("m_auto_indentation", &TextEditor::LanguageDefinition::mAutoIndentation, "")
            .def_readwrite("m_token_regex_strings", &TextEditor::LanguageDefinition::mTokenRegexStrings, "")
            .def_readwrite("m_case_sensitive", &TextEditor::LanguageDefinition::mCaseSensitive, "")
            .def(py::init<>())
            .def_static("c_plus_plus",
                &TextEditor::LanguageDefinition::CPlusPlus)
            .def_static("hlsl",
                &TextEditor::LanguageDefinition::HLSL)
            .def_static("glsl",
                &TextEditor::LanguageDefinition::GLSL)
            .def_static("c",
                &TextEditor::LanguageDefinition::C)
            .def_static("sql",
                &TextEditor::LanguageDefinition::SQL)
            .def_static("angel_script",
                &TextEditor::LanguageDefinition::AngelScript)
            .def_static("lua",
                &TextEditor::LanguageDefinition::Lua)
            .def_static("python",
                &TextEditor::LanguageDefinition::Python)
            ;
    } // end of inner classes & enums of TextEditor

    pyClassTextEditor
        .def(py::init<>())
        .def("set_language_definition",
            &TextEditor::SetLanguageDefinition, py::arg("a_language_def"))
        .def("get_language_definition",
            &TextEditor::GetLanguageDefinition)
        .def("get_palette",
            &TextEditor::GetPalette)
        .def("set_palette",
            &TextEditor::SetPalette, py::arg("a_value"))
        .def("set_error_markers",
            &TextEditor::SetErrorMarkers, py::arg("a_markers"))
        .def("set_breakpoints",
            &TextEditor::SetBreakpoints, py::arg("a_markers"))
        .def("render",
            py::overload_cast<const char *, const ImVec2 &, bool>(&TextEditor::Render), py::arg("a_title"), py::arg("a_size") = ImVec2(), py::arg("a_border") = false)
        .def("set_text",
            &TextEditor::SetText, py::arg("a_text"))
        .def("get_text",
            [](TextEditor & self) { return self.GetText(); })
        .def("set_text_lines",
            &TextEditor::SetTextLines, py::arg("a_lines"))
        .def("get_text_lines",
            &TextEditor::GetTextLines)
        .def("get_selected_text",
            &TextEditor::GetSelectedText)
        .def("get_current_line_text",
            &TextEditor::GetCurrentLineText)
        .def("get_total_lines",
            &TextEditor::GetTotalLines)
        .def("is_overwrite",
            &TextEditor::IsOverwrite)
        .def("set_read_only",
            &TextEditor::SetReadOnly, py::arg("a_value"))
        .def("is_read_only",
            &TextEditor::IsReadOnly)
        .def("is_text_changed",
            &TextEditor::IsTextChanged)
        .def("is_cursor_position_changed",
            &TextEditor::IsCursorPositionChanged)
        .def("is_colorizer_enabled",
            &TextEditor::IsColorizerEnabled)
        .def("set_colorizer_enable",
            &TextEditor::SetColorizerEnable, py::arg("a_value"))
        .def("get_cursor_position",
            &TextEditor::GetCursorPosition)
        .def("set_cursor_position",
            &TextEditor::SetCursorPosition, py::arg("a_position"), py::arg("cursor_line_on_page") = -1)
        .def("set_handle_mouse_inputs",
            &TextEditor::SetHandleMouseInputs, py::arg("a_value"))
        .def("is_handle_mouse_inputs_enabled",
            &TextEditor::IsHandleMouseInputsEnabled)
        .def("set_handle_keyboard_inputs",
            &TextEditor::SetHandleKeyboardInputs, py::arg("a_value"))
        .def("is_handle_keyboard_inputs_enabled",
            &TextEditor::IsHandleKeyboardInputsEnabled)
        .def("set_im_gui_child_ignored",
            &TextEditor::SetImGuiChildIgnored, py::arg("a_value"))
        .def("is_im_gui_child_ignored",
            &TextEditor::IsImGuiChildIgnored)
        .def("set_show_whitespaces",
            &TextEditor::SetShowWhitespaces, py::arg("a_value"))
        .def("is_showing_whitespaces",
            &TextEditor::IsShowingWhitespaces)
        .def("set_show_short_tab_glyphs",
            &TextEditor::SetShowShortTabGlyphs, py::arg("a_value"))
        .def("is_showing_short_tab_glyphs",
            &TextEditor::IsShowingShortTabGlyphs)
        .def("set_tab_size",
            &TextEditor::SetTabSize, py::arg("a_value"))
        .def("get_tab_size",
            &TextEditor::GetTabSize)
        .def("insert_text",
            py::overload_cast<const std::string &>(&TextEditor::InsertText), py::arg("a_value"))
        .def("insert_text",
            py::overload_cast<const char *>(&TextEditor::InsertText), py::arg("a_value"))
        .def("move_up",
            &TextEditor::MoveUp, py::arg("a_amount") = 1, py::arg("a_select") = false)
        .def("move_down",
            &TextEditor::MoveDown, py::arg("a_amount") = 1, py::arg("a_select") = false)
        .def("move_left",
            &TextEditor::MoveLeft, py::arg("a_amount") = 1, py::arg("a_select") = false, py::arg("a_word_mode") = false)
        .def("move_right",
            &TextEditor::MoveRight, py::arg("a_amount") = 1, py::arg("a_select") = false, py::arg("a_word_mode") = false)
        .def("move_top",
            &TextEditor::MoveTop, py::arg("a_select") = false)
        .def("move_bottom",
            &TextEditor::MoveBottom, py::arg("a_select") = false)
        .def("move_home",
            &TextEditor::MoveHome, py::arg("a_select") = false)
        .def("move_end",
            &TextEditor::MoveEnd, py::arg("a_select") = false)
        .def("set_selection_start",
            &TextEditor::SetSelectionStart, py::arg("a_position"))
        .def("set_selection_end",
            &TextEditor::SetSelectionEnd, py::arg("a_position"))
        .def("set_selection",
            &TextEditor::SetSelection, py::arg("a_start"), py::arg("a_end"), py::arg("a_mode") = TextEditor::SelectionMode::Normal)
        .def("select_word_under_cursor",
            &TextEditor::SelectWordUnderCursor)
        .def("select_all",
            &TextEditor::SelectAll)
        .def("has_selection",
            &TextEditor::HasSelection)
        .def("copy",
            &TextEditor::Copy)
        .def("cut",
            &TextEditor::Cut)
        .def("paste",
            &TextEditor::Paste)
        .def("delete",
            &TextEditor::Delete)
        .def("can_undo",
            &TextEditor::CanUndo)
        .def("can_redo",
            &TextEditor::CanRedo)
        .def("undo",
            &TextEditor::Undo, py::arg("a_steps") = 1)
        .def("redo",
            &TextEditor::Redo, py::arg("a_steps") = 1)
        .def_static("get_dark_palette",
            &TextEditor::GetDarkPalette)
        .def_static("get_light_palette",
            &TextEditor::GetLightPalette)
        .def_static("get_retro_blue_palette",
            &TextEditor::GetRetroBluePalette)
        ;
    ////////////////////    </generated_from:TextEditor.h>    ////////////////////

    // </litgen_pydef> // Autogenerated code end
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE END !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}
