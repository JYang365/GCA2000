#pragma once
#include "EuroScopePlugIn.h"

// ReSharper disable once CppInconsistentNaming
class CGCAScreen final :
	public EuroScopePlugIn::CRadarScreen
{
	void draw_glideslope_axes(CDC *dc, CRect area, CPen* pen, double max_range, double max_alt) const;
	void draw_deviation_cross(CDC* dc, CRect area, CPen* pen) const;
	void draw_glideslope(CDC* dc, CRect area, CPen* pen, double max_range, double max_alt) const;
	void draw_radar_cursors(CDC* dc, const CRect area, CPen* pen, const double max_range, const double max_alt) const;
	void draw_obstacle_clearance_height(CDC* dc, CRect area, CPen* pen, double max_range, double max_alt) const;
	static void draw_glideslope_runway(CDC* dc, CRect area, CPen* pen);
	void draw_middle_text(CDC* dc, CRect area) const;
	void draw_track_axes(CDC* dc, CRect area, CPen* pen, double max_range, int max_track_error) const;
	static void draw_track_runway(CDC* dc, CRect area, CPen* pen);
public:
	CString description_; // Radar description
	CString lat_, lon_; // Threshold coordinates
	double altitude_; // Threshold altitude
	double obstacle_clearance_height_; // Obstacle Clearance Height
	double heading_; // Final Approach Heading
	double glide_slope_; // Glidepath angle
	EuroScopePlugIn::CPosition    runway_position_; // Runway threshold
	double scope_max_height_; // max height of slope
	double max_range_; //max range of radar screen
	double max_track_error_; //max lateral dev from track
public:
	CGCAScreen();
	virtual ~CGCAScreen();
	void OnAsrContentLoaded(bool loaded) override;
	void OnAsrContentToBeSaved() override;
	// ReSharper disable once CppInconsistentNaming
	void OnRefresh(const HDC hDC, int phase) override;
	//bool OnCompileCommand(const char* sCommandLine) override;
	void OnAsrContentToBeClosed() override
	{
		delete this;
	}
};

