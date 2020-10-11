
#include "./implot/implot.h"
#include "cimplot.h"



#include "auto_funcs.cpp"

//ImPlotPoint getters manually wrapped for taking getters returning ImPlotPoint*
ImPlotPoint *(*getter_funcX)(void* data, int idx);
ImPlotPoint *(*getter_funcX2)(void* data, int idx);

ImPlotPoint Wrapper(void* data, int idx)
{
	ImPlotPoint *pp = getter_funcX(data, idx);
	return *pp;
}

ImPlotPoint Wrapper2(void* data, int idx)
{
	ImPlotPoint *pp = getter_funcX2(data, idx);
	return *pp;
}

CIMGUI_API void ImPlot_PlotLineG(const char* label_id,ImPlotPoint*(*getter)(void* data,int idx),void* data,int count,int offset)
{
    getter_funcX = getter;
	ImPlot::PlotLineG(label_id,Wrapper,data,count,offset);
}

CIMGUI_API  void ImPlot_PlotScatterG(const char* label_id, ImPlotPoint *(*getter)(void* data, int idx), void* data, int count, int offset)
{
	getter_funcX = getter;
	ImPlot::PlotScatterG(label_id, Wrapper, data, count, offset);
}

CIMGUI_API void ImPlot_PlotShadedG(const char* label_id, ImPlotPoint* (*getter1)(void* data, int idx), void* data1, ImPlotPoint* (*getter2)(void* data, int idx), void* data2, int count, int offset)
{
	getter_funcX = getter1;
	getter_funcX2 = getter2;
	ImPlot::PlotShadedG(label_id, Wrapper, data1, Wrapper2, data2, count, offset);
}

CIMGUI_API void ImPlot_PlotBarsG(const char* label_id, ImPlotPoint* (*getter)(void* data, int idx), void* data, int count, double width, int offset)
{
	getter_funcX = getter;
	ImPlot::PlotBarsG(label_id, Wrapper, data, count, width, offset);
}

CIMGUI_API void ImPlot_PlotBarsHG(const char* label_id, ImPlotPoint* (*getter)(void* data, int idx), void* data, int count, double height,  int offset)
{
	getter_funcX = getter;
	ImPlot::PlotBarsHG(label_id, Wrapper, data, count, height, offset);
}

CIMGUI_API void ImPlot_PlotDigitalG(const char* label_id, ImPlotPoint* (*getter)(void* data, int idx), void* data, int count, int offset)
{
	getter_funcX = getter;
	ImPlot::PlotDigitalG(label_id, Wrapper, data, count, offset);
}