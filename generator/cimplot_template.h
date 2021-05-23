#ifndef CIMGUIPLOT_INCLUDED
#define CIMGUIPLOT_INCLUDED

#include "cimgui.h"

#ifdef CIMGUI_DEFINE_ENUMS_AND_STRUCTS
#include <time.h>
typedef struct tm tm;

#include "imgui_structs.h"
#else

#endif // CIMGUI_DEFINE_ENUMS_AND_STRUCTS

#include "auto_funcs.h"

typedef void *(*ImPlotPoint_getter)(void* data, int idx, ImPlotPoint *point);

//ImPlotPoint getters manually wrapped
CIMGUI_API void ImPlot_PlotLineG(const char* label_id,ImPlotPoint_getter getter,void* data,int count,int offset);
CIMGUI_API  void ImPlot_PlotScatterG(const char* label_id, ImPlotPoint_getter getter, void* data, int count, int offset);
CIMGUI_API void ImPlot_PlotShadedG(const char* label_id, ImPlotPoint_getter getter1, void* data1, ImPlotPoint_getter getter2, void* data2, int count, int offset);
CIMGUI_API void ImPlot_PlotBarsG(const char* label_id, ImPlotPoint_getter getter, void* data, int count, double width, int offset);
CIMGUI_API void ImPlot_PlotBarsHG(const char* label_id, ImPlotPoint_getter getter, void* data, int count, double height,  int offset);
CIMGUI_API void ImPlot_PlotDigitalG(const char* label_id, ImPlotPoint_getter getter, void* data, int count, int offset);

#endif //CIMGUIPLOT_INCLUDED




