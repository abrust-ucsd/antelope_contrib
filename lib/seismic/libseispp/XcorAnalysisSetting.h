//  Peng Wang, HPC/RAC/UITS
//  Indiana University
//
//  Copyright 2005, The Trustees of Indiana University.
//  Last Modified: 12/1/2005


#ifndef __ANALYSIS_SETTING_H
#define __ANALYSIS_SETTING_H


#include <vector>
#include "Metadata.h"
#include "TimeWindow.h"
#include "filter++.h"
#include "stack.h"
namespace SEISPP {

using namespace std;
using namespace SEISPP;

// Analysis results can be sorted by these keys
// made an enum for convenience.  
enum SortOrder {COHERENCE,CORRELATION_PEAK,AMPLITUDE,LAG,WEIGHT,
	SITE_LAT,SITE_LON,PREDARR_TIME,ESAZ,DISTANCE,ARRIVAL_TIME,
	DBARRIVAL_TIME,SNR};

//@{ Encapsulates all quantities required by XcorProcessingEngine in 
//   a single data structure.  
//@}
class XcorAnalysisSetting {
public:
	XcorAnalysisSetting() {aw_set=false; bw_set=false; rw_set=false; rt_set=false;}
	XcorAnalysisSetting(Metadata md);
	XcorAnalysisSetting(const XcorAnalysisSetting& old);
	XcorAnalysisSetting& operator=(const XcorAnalysisSetting& old);
	void set_analysis_tw(TimeWindow tw_in) {aw_set=true; analysis_tw=tw_in;}
	void set_beam_tw(TimeWindow tw_in) {bw_set=true; beam_tw=tw_in;}
	void set_robust_tw(TimeWindow tw_in) {rw_set=true; robust_tw=tw_in;}
	void set_ref_trace(int trace) {rt_set=true; reference_trace=trace;};	

        bool aw_set;
	bool bw_set;
	bool rw_set;
	bool rt_set;

	TimeWindow gather_twin;
        TimeWindow analysis_tw;
        TimeWindow beam_tw;
        TimeWindow robust_tw;
        int reference_trace;
        vector<int> removed_traces;
        StackType stack_type;
        double phase_time_pick;
        TimeInvariantFilter filter_param;
        int component_for_analysis;
	string component_name;
	string arrival_chan_code;
        string phase_for_analysis;
        double tpad;  // fudge factor needed for input
	// Added by GLP 1/6/2006
	SortOrder result_sort_order;
	bool sort_reverse;
};

} // end SEISPP namespace declaration
#endif
