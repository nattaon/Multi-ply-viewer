#include<iostream>
using namespace std; 
class JetColormap 
{ 
    // Access specifier 
    public: 
  
    // Data Members 
  float colormap[256][3] = 
{
{0, 0, 0},//{0, 0, 0.5},
{0, 0, 0.515686},
{0, 0, 0.531373},
{0, 0, 0.547059},
{0, 0, 0.562745},
{0, 0, 0.578431},
{0, 0, 0.594118},
{0, 0, 0.609804},
{0, 0, 0.62549},
{0, 0, 0.641176},
{0, 0, 0.656863},
{0, 0, 0.672549},
{0, 0, 0.688235},
{0, 0, 0.703922},
{0, 0, 0.719608},
{0, 0, 0.735294},
{0, 0, 0.75098},
{0, 0, 0.766667},
{0, 0, 0.782353},
{0, 0, 0.798039},
{0, 0, 0.813725},
{0, 0, 0.829412},
{0, 0, 0.845098},
{0, 0, 0.860784},
{0, 0, 0.876471},
{0, 0, 0.892157},
{0, 0, 0.907843},
{0, 0, 0.923529},
{0, 0, 0.939216},
{0, 0, 0.954902},
{0, 0, 0.970588},
{0, 0, 0.986275},
{0, 0.00196078, 1},
{0, 0.0176471, 1},
{0, 0.0333333, 1},
{0, 0.0490196, 1},
{0, 0.0647059, 1},
{0, 0.0803922, 1},
{0, 0.0960784, 1},
{0, 0.111765, 1},
{0, 0.127451, 1},
{0, 0.143137, 1},
{0, 0.158824, 1},
{0, 0.17451, 1},
{0, 0.190196, 1},
{0, 0.205882, 1},
{0, 0.221569, 1},
{0, 0.237255, 1},
{0, 0.252941, 1},
{0, 0.268627, 1},
{0, 0.284314, 1},
{0, 0.3, 1},
{0, 0.315686, 1},
{0, 0.331373, 1},
{0, 0.347059, 1},
{0, 0.362745, 1},
{0, 0.378431, 1},
{0, 0.394118, 1},
{0, 0.409804, 1},
{0, 0.42549, 1},
{0, 0.441176, 1},
{0, 0.456863, 1},
{0, 0.472549, 1},
{0, 0.488235, 1},
{0, 0.503922, 1},
{0, 0.519608, 1},
{0, 0.535294, 1},
{0, 0.55098, 1},
{0, 0.566667, 1},
{0, 0.582353, 1},
{0, 0.598039, 1},
{0, 0.613725, 1},
{0, 0.629412, 1},
{0, 0.645098, 1},
{0, 0.660784, 1},
{0, 0.676471, 1},
{0, 0.692157, 1},
{0, 0.707843, 1},
{0, 0.723529, 1},
{0, 0.739216, 1},
{0, 0.754902, 1},
{0, 0.770588, 1},
{0, 0.786275, 1},
{0, 0.801961, 1},
{0, 0.817647, 1},
{0, 0.833333, 1},
{0, 0.84902, 1},
{0, 0.864706, 1},
{0, 0.880392, 1},
{0, 0.896078, 1},
{0, 0.911765, 1},
{0, 0.927451, 1},
{0, 0.943137, 1},
{0, 0.958824, 1},
{0, 0.97451, 1},
{0, 0.990196, 1},
{0.00588235, 1, 0.994118},
{0.0215686, 1, 0.978431},
{0.0372549, 1, 0.962745},
{0.0529412, 1, 0.947059},
{0.0686275, 1, 0.931373},
{0.0843137, 1, 0.915686},
{0.1, 1, 0.9},
{0.115686, 1, 0.884314},
{0.131373, 1, 0.868627},
{0.147059, 1, 0.852941},
{0.162745, 1, 0.837255},
{0.178431, 1, 0.821569},
{0.194118, 1, 0.805882},
{0.209804, 1, 0.790196},
{0.22549, 1, 0.77451},
{0.241176, 1, 0.758824},
{0.256863, 1, 0.743137},
{0.272549, 1, 0.727451},
{0.288235, 1, 0.711765},
{0.303922, 1, 0.696078},
{0.319608, 1, 0.680392},
{0.335294, 1, 0.664706},
{0.35098, 1, 0.64902},
{0.366667, 1, 0.633333},
{0.382353, 1, 0.617647},
{0.398039, 1, 0.601961},
{0.413725, 1, 0.586275},
{0.429412, 1, 0.570588},
{0.445098, 1, 0.554902},
{0.460784, 1, 0.539216},
{0.476471, 1, 0.523529},
{0.492157, 1, 0.507843},
{0.507843, 1, 0.492157},
{0.523529, 1, 0.476471},
{0.539216, 1, 0.460784},
{0.554902, 1, 0.445098},
{0.570588, 1, 0.429412},
{0.586275, 1, 0.413725},
{0.601961, 1, 0.398039},
{0.617647, 1, 0.382353},
{0.633333, 1, 0.366667},
{0.64902, 1, 0.35098},
{0.664706, 1, 0.335294},
{0.680392, 1, 0.319608},
{0.696078, 1, 0.303922},
{0.711765, 1, 0.288235},
{0.727451, 1, 0.272549},
{0.743137, 1, 0.256863},
{0.758824, 1, 0.241176},
{0.77451, 1, 0.22549},
{0.790196, 1, 0.209804},
{0.805882, 1, 0.194118},
{0.821569, 1, 0.178431},
{0.837255, 1, 0.162745},
{0.852941, 1, 0.147059},
{0.868627, 1, 0.131373},
{0.884314, 1, 0.115686},
{0.9, 1, 0.1},
{0.915686, 1, 0.0843137},
{0.931373, 1, 0.0686275},
{0.947059, 1, 0.0529412},
{0.962745, 1, 0.0372549},
{0.978431, 1, 0.0215686},
{0.994118, 1, 0.00588235},
{1, 0.990196, 0},
{1, 0.97451, 0},
{1, 0.958824, 0},
{1, 0.943137, 0},
{1, 0.927451, 0},
{1, 0.911765, 0},
{1, 0.896078, 0},
{1, 0.880392, 0},
{1, 0.864706, 0},
{1, 0.84902, 0},
{1, 0.833333, 0},
{1, 0.817647, 0},
{1, 0.801961, 0},
{1, 0.786275, 0},
{1, 0.770588, 0},
{1, 0.754902, 0},
{1, 0.739216, 0},
{1, 0.723529, 0},
{1, 0.707843, 0},
{1, 0.692157, 0},
{1, 0.676471, 0},
{1, 0.660784, 0},
{1, 0.645098, 0},
{1, 0.629412, 0},
{1, 0.613725, 0},
{1, 0.598039, 0},
{1, 0.582353, 0},
{1, 0.566667, 0},
{1, 0.55098, 0},
{1, 0.535294, 0},
{1, 0.519608, 0},
{1, 0.503922, 0},
{1, 0.488235, 0},
{1, 0.472549, 0},
{1, 0.456863, 0},
{1, 0.441176, 0},
{1, 0.42549, 0},
{1, 0.409804, 0},
{1, 0.394118, 0},
{1, 0.378431, 0},
{1, 0.362745, 0},
{1, 0.347059, 0},
{1, 0.331373, 0},
{1, 0.315686, 0},
{1, 0.3, 0},
{1, 0.284314, 0},
{1, 0.268627, 0},
{1, 0.252941, 0},
{1, 0.237255, 0},
{1, 0.221569, 0},
{1, 0.205882, 0},
{1, 0.190196, 0},
{1, 0.17451, 0},
{1, 0.158824, 0},
{1, 0.143137, 0},
{1, 0.127451, 0},
{1, 0.111765, 0},
{1, 0.0960784, 0},
{1, 0.0803922, 0},
{1, 0.0647059, 0},
{1, 0.0490196, 0},
{1, 0.0333333, 0},
{1, 0.0176471, 0},
{1, 0.00196078, 0},
{0.986275, 0, 0},
{0.970588, 0, 0},
{0.954902, 0, 0},
{0.939216, 0, 0},
{0.923529, 0, 0},
{0.907843, 0, 0},
{0.892157, 0, 0},
{0.876471, 0, 0},
{0.860784, 0, 0},
{0.845098, 0, 0},
{0.829412, 0, 0},
{0.813725, 0, 0},
{0.798039, 0, 0},
{0.782353, 0, 0},
{0.766667, 0, 0},
{0.75098, 0, 0},
{0.735294, 0, 0},
{0.719608, 0, 0},
{0.703922, 0, 0},
{0.688235, 0, 0},
{0.672549, 0, 0},
{0.656863, 0, 0},
{0.641176, 0, 0},
{0.62549, 0, 0},
{0.609804, 0, 0},
{0.594118, 0, 0},
{0.578431, 0, 0},
{0.562745, 0, 0},
{0.547059, 0, 0},
{0.531373, 0, 0},
{0.515686, 0, 0},
{0.5, 0, 0},
};
  
}; 