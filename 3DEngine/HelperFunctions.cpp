#include "HelperFunctions.h"






void RenderTextInternal(float x, float y, int fontIdx, float fontScale, uint32_t color, uint32_t outlineColor, const char* szText, ...) {

    char buf[0x400];

    ImVec2 from;
    from.x = x;
    from.y = y;

    va_list va_alist;

    va_start(va_alist, szText);
    vsprintf_s(buf, szText, va_alist);
    va_end(va_alist);

    auto window = ImGui::GetCurrentWindow();

    auto font = ImGui::GetFont();

    if (font != nullptr)
        ImGui::PushFont(font);

    auto scale = window->DrawList->_Data->Font->Scale;

    window->DrawList->_Data->Font->Scale = fontScale;

    if (outlineColor) {
        window->DrawList->AddText(ImVec2(x + 1, y), outlineColor, buf);
        window->DrawList->AddText(ImVec2(x - 1, y), outlineColor, buf);
        window->DrawList->AddText(ImVec2(x, y + 1), outlineColor, buf);
        window->DrawList->AddText(ImVec2(x, y - 1), outlineColor, buf);
    }

    window->DrawList->AddText(from, color, buf);

    window->DrawList->_Data->Font->Scale = scale;

    if (font != nullptr)
        ImGui::PopFont();
}

void DrawLine(float x, float y, float x1, float y1, uint32_t color, float thickness) {


    ImVec2 from, to;
    from.x = x;
    from.y = y;
    to.x = x1;
    to.y = y1;

    auto window = ImGui::GetCurrentWindow();

    window->DrawList->AddLine(from, to, color, thickness);
}

    void DrawCube(float x, float y, float x1, float y1, uint32_t color, float thickness) {
    
        auto window = ImGui::GetCurrentWindow();

        double fraction = 16.666667;
       
        float x2 = x - x / fraction;
        float x3 = x1 - x1 / fraction;

        float y2 = y - y/ fraction;
        float y3 = y1 - y1 / fraction;


        ImVec2 from, to;
        from.x = x;
        from.y = y;
        to.x = x1;
        to.y = y;

    

        window->DrawList->AddLine(from, to, color, thickness);

        from.x = x;
        from.y = y1;
        to.x = x1;
        to.y = y1;

        window->DrawList->AddLine(from, to, color, thickness);
    
        from.x = x;
        from.y = y;
        to.x = x;
        to.y = y1;

        window->DrawList->AddLine(from, to, color, thickness);

        from.x = x1;
        from.y = y;
        to.x = x1;
        to.y = y1;

        window->DrawList->AddLine(from, to, color, thickness);





        from.x = x;
        from.y = y;
        to.x = x2;
        to.y = y2;

        window->DrawList->AddLine(from, to, color, thickness);

        from.x = x;
        from.y = y;
        to.x = x2;
        to.y = y2;

        window->DrawList->AddLine(from, to, color, thickness);

        from.x = x;
        from.y = y1;
        to.x = x2;
        to.y = y3;

        window->DrawList->AddLine(from, to, color, thickness);

        from.x = x2;
        from.y = y2;
        to.x = x2;
        to.y = y3;

        window->DrawList->AddLine(from, to, color, thickness);

        from.x = x2;
        from.y = y2;
        to.x = x3;
        to.y = y2;

        window->DrawList->AddLine(from, to, color, thickness);

        from.x = x3;
        from.y = y2;
        to.x = x1;
        to.y = y;

        window->DrawList->AddLine(from, to, color, thickness);

        from.x = x3;
        from.y = y2;
        to.x = x3;
        to.y = y3;  

        window->DrawList->AddLine(from, to, color, thickness);

        from.x = x3;
        from.y = y3;
        to.x = x1;
        to.y = y1;

        window->DrawList->AddLine(from, to, color, thickness);

        from.x = x3;
        from.y = y3;
        to.x = x2;
        to.y = y3;

        window->DrawList->AddLine(from, to, color,  thickness);

    
    }

    float Lerp(float start, float end, float amount) {

        return start + (end - start) * amount;
    }


void DrawCircle(float x, float y, float radius, uint32_t color, float thickness, uint32_t segments) {

    ImVec2 position;
    position.x = x;
    position.y = y;

    auto window = ImGui::GetCurrentWindow();

    window->DrawList->AddCircle(position, radius, color, segments);

}

void DrawCircleFilled(float x, float y, float radius, uint32_t color, float thickness, uint32_t segments) {


    ImVec2 position;
    position.x = x;
    position.y = y;

    auto window = ImGui::GetCurrentWindow();

    window->DrawList->AddCircleFilled(position, radius, color, segments);

}

void RenderImage(void* pTexture, float x, float y, float x1, float y1, uint32_t color, uint32_t outlineColor) {

    ImVec2 position, extent;
    position.x = x;
    position.y = y;

    extent.x = x + x1;
    extent.y = y + y1;

    auto window = ImGui::GetCurrentWindow();

    if (outlineColor) {
        window->DrawList->AddImage(pTexture, ImVec2(x - 1.2f, y - 1.2f), ImVec2(extent.x + 1.2f, extent.y + 1.2f), ImVec2(0, 0), ImVec2(1, 1), outlineColor);

    }

    window->DrawList->AddImage(pTexture, position, extent, ImVec2(0, 0), ImVec2(1, 1), color);
}

void RenderImageRounded(ImTextureID* pTexture, float x, float y, float x1, float y1, uint32_t color, float rounding, uint32_t roundingCornersFlags) {

    ImVec2 position, extent;
    position.x = x;
    position.y = y;

    extent.x = x + x1;
    extent.y = y + y1;

    auto window = ImGui::GetCurrentWindow();

    window->DrawList->AddImageRounded(pTexture, position, extent, { 0.0f, 0.0f }, { 1.0f, 1.0f }, color, rounding, roundingCornersFlags);
}





