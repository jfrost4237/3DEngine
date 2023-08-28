#pragma once


#include <stdio.h>
#include <d3d11.h>
#include <tchar.h>
#include <cstdint>
#include <sdkddkver.h>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_internal.h"





#define xorstr(x) x

#ifndef D3DCOLOR_ABGR
#define D3DCOLOR_ABGR(a,b,g,r) \
    ((uint32_t)((((a)&0xff)<<24)|(((b)&0xff)<<16)|(((g)&0xff)<<8)|((r)&0xff)))
#endif