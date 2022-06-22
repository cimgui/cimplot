
#include "./implot/implot.h"
#include "./implot/implot_internal.h"
#include "cimplot.h"



#include "auto_funcs.cpp"

//ImPlotPoint getters manually wrapped for taking getters modifying ImPlotPoint*

ImPlotPoint_getter getter_funcX;
ImPlotPoint_getter getter_funcX2;

ImPlotPoint Wrapper(int idx, void* data)
{
	ImPlotPoint pp;
	getter_funcX(data, idx, &pp);
	return pp;
}

ImPlotPoint Wrapper2(int idx, void* data)
{
	ImPlotPoint pp;
	getter_funcX2(data, idx, &pp);
	return pp;
}

CIMGUI_API void ImPlot_PlotLineG(const char* label_id, ImPlotPoint_getter getter,void* data,int count,ImPlotLineFlags flags)
{
    getter_funcX = getter;
	ImPlot::PlotLineG(label_id,Wrapper,data,count,flags);
}

CIMGUI_API  void ImPlot_PlotScatterG(const char* label_id, ImPlotPoint_getter getter, void* data, int count)
{
	getter_funcX = getter;
	ImPlot::PlotScatterG(label_id, Wrapper, data, count);
}

CIMGUI_API void ImPlot_PlotShadedG(const char* label_id, ImPlotPoint_getter getter1, void* data1, ImPlotPoint_getter getter2, void* data2, int count)
{
	getter_funcX = getter1;
	getter_funcX2 = getter2;
	ImPlot::PlotShadedG(label_id, Wrapper, data1, Wrapper2, data2, count);
}

CIMGUI_API void ImPlot_PlotBarsG(const char* label_id, ImPlotPoint_getter getter, void* data, int count, double width)
{
	getter_funcX = getter;
	ImPlot::PlotBarsG(label_id, Wrapper, data, count, width);
}
/*
CIMGUI_API void ImPlot_PlotBarsHG(const char* label_id, ImPlotPoint_getter getter, void* data, int count, double height)
{
	getter_funcX = getter;
	ImPlot::PlotBarsHG(label_id, Wrapper, data, count, height);
}
*/
CIMGUI_API void ImPlot_PlotDigitalG(const char* label_id, ImPlotPoint_getter getter, void* data, int count)
{
	getter_funcX = getter;
	ImPlot::PlotDigitalG(label_id, Wrapper, data, count);
}