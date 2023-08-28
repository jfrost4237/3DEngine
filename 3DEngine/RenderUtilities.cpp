#include "RenderUtilities.h"

//HWND GetOurWindowHandle() {
//    LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
//
//
//    WNDCLASSEXW wc = { sizeof(wc), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, L"ImGui Example", nullptr };
//    ::RegisterClassExW(&wc);
//    
//    HWND hwnd = CreateWindowW(wc.lpszClassName, L"Good Shit", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr, wc.hInstance, nullptr);
//
//    return hwnd;
//}



//void GetScreenSize(float* size) {
//
//    RECT rect;
//
//    const HWND windowHandle = GetOurWindowHandle();
//
//    GetClientRect(windowHandle, &rect);
//
//    size[0] = static_cast<float>(rect.right - rect.left);
//
//    size[1] = static_cast<float>(rect.bottom - rect.top);
//}
