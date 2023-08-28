#pragma once
//#include "include.h"

#include "include.h"


//void GetScreenSize(float* size);
//
//void GetOurWindowHandle();

void RenderTextInternal(float x, float y, int fontIdx, float fontScale, uint32_t color, uint32_t outlineColor, const char* szText, ...);

void DrawLine(float x, float y, float x1, float y1, uint32_t color, float thickness);
void DrawCube(float x, float y, float x1, float y1, uint32_t color, float thickness);

void DrawCircle(float x, float y, float radius, uint32_t color, float thickness, uint32_t segments);

void DrawCircleFilled(float x, float y, float radius, uint32_t color, float thickness, uint32_t segments);

float Lerp(float start, float end, float amount);

void RenderImage(void* pTexture, float x, float y, float x1, float y1, uint32_t color, uint32_t outlineColor);

void RenderImageRounded(ImTextureID* pTexture, float x, float y, float x1, float y1, uint32_t color, float rounding, uint32_t roundingCornersFlags);
