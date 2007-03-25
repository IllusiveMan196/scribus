/*
For general Scribus (>=1.3.2) copyright and licensing information please refer
to the COPYING file provided with the program. Following this notice may exist
a copyright and/or license notice that predates the release of Scribus 1.3.2
for which a new license (GPL+exception) is in place.
*/
#ifndef TABTOOLS_H
#define TABTOOLS_H

#include <qvariant.h>
#include <qwidget.h>
#include <qlayout.h>
#include <qlabel.h>
#include <qtoolbutton.h>
#include <qbuttongroup.h>
#include <qcombobox.h>
#include <qcheckbox.h>
#include <qradiobutton.h>
#include <qwidgetstack.h>

#include "scribusapi.h"

class QGroupBox;
class LinkButton;
class QSpinBox;
class FontCombo;
class PolygonWidget;
class ArrowChooser;
class MSpinBox;
class LineCombo;
class ScribusDoc;
class ColorCombo;


/*! \brief Tools panel for preferences dialog.
This class is inherited from UI base class.
\author Petr Vanek <petr@scribus.info>
*/
class SCRIBUS_API TabTools : public QWidget
{
	Q_OBJECT

public:
	TabTools( QWidget* parent, struct toolPrefs *prefsData, int unitIndex, ScribusDoc* doc);
	~TabTools() {};

	void restoreDefaults(struct toolPrefs *prefsData, int unitIndex);

	/*! \brief Enable sample rendering.
	It's called when user selects this panel in preferences. First painting is very slow
	so it's called on user demand - not in the prefs GUI initialization.
	\param state allow drawing the sample when TRUE
	\author Petr Vanek <petr@scribus.info> */
	void enableFontPreview(bool state);

	void unitChange(QString unit, int docUnitIndex, int decimals, double invUnitConversion);

	QButtonGroup* buttonGroupTools;
	QToolButton* toolShape;
	QToolButton* toolPoly;
	QToolButton* toolImage;
	QToolButton* toolText;
	QToolButton* toolLine;
	QToolButton* toolZoom;
	QToolButton* toolMisc;
	QWidgetStack* subStackTools;
	QWidget* subTabText;
	QLabel* textHeadLine;
	QLabel* textLabel3b;
	QLabel* textLabel3b2;
	QLabel* textLabel3b2t;
	QLabel* textLabel3b2t2;
	QLabel* textLabel3bT;
	QLabel* textLabel3bTL;
	QLabel* textLabel1b;
	QLabel* textLabel2b;
	QLabel* textLabel4b;
	QSpinBox* columnsText;
	QLabel* previewText;
	FontCombo* fontComboText;
	QComboBox* sizeComboText;
	ColorCombo* colorComboText;
	ColorCombo* colorComboStrokeText;
	ColorCombo* colorComboTextBackground;
	ColorCombo* colorComboTextLine;
	QSpinBox* shadingText;
	QSpinBox* shadingTextStroke;
	QSpinBox* shadingTextBack;
	QSpinBox* shadingTextLine;
	QLabel* textLabelTS;
	QLabel* textLabelTSS;
	QLabel* textLabelTSB;
	QLabel* textLabelTSL;
	QComboBox* tabFillCombo;
	QLabel* textLabel5b;
	MSpinBox* gapText;
	MSpinBox* gapTab;
	QWidget* subTabShape;
	QLabel* shapeHeadLine;
	QLabel* textLabel9b;
	QLabel* textLabel10b;
	MSpinBox* lineWidthShape;
	QLabel* textLabel12b;
	QLabel* textLabel11b;
	LineCombo* comboStyleShape;
	QSpinBox* shadingFillShape;
	ColorCombo* comboFillShape;
	QSpinBox* shadingLineShape;
	QLabel* textLabel7b;
	ColorCombo* colorComboLineShape;
	QLabel* textLabel8b;
	QWidget* subTabLine;
	QLabel* lineHeadLine;
	MSpinBox* lineWidthLine;
	QSpinBox* shadingLine;
	ColorCombo* colorComboLine;
	QLabel* textLabel13b;
	QLabel* textLabel14b;
	QLabel* textLabel15b;
	QLabel* textLabel16b;
	LineCombo* comboStyleLine;
	QWidget* subTabImage;
	QLabel* imageHeadLine;
	ColorCombo* comboFillImage;
	QLabel* textLabel19b;
	QSpinBox* shadingFillImage;
	QLabel* textLabel20b;
	QButtonGroup* buttonGroup3;
	QLabel* textLabel17b;
	QLabel* textLabel18b;
	QSpinBox* scalingHorizontal;
	QSpinBox* scalingVertical;
	LinkButton* chainButton;
	QButtonGroup* buttonGroup5;
	QCheckBox* checkRatioImage;
	QCheckBox* embeddedPath;
	QButtonGroup* buttonGroupRes;
	QRadioButton* checkFullRes;
	QRadioButton* checkNormalRes;
	QRadioButton* checkHalfRes;
	QWidget* subTabPolygon;
	QLabel* polygonHeadLine;
	PolygonWidget* polyWidget;
	QWidget* subTabZoom;
	QLabel* zoomHeadLine;
	QLabel* textLabel21b;
	QSpinBox* minimumZoom;
	QLabel* textLabel22b;
	QLabel* textLabel23b;
	QSpinBox* maximumZoom;
	QSpinBox* zoomStep;
	ArrowChooser* startArrow;
	ArrowChooser* endArrow;
	QLabel* startArrowText;
	QLabel* endArrowText;
	QLabel* arrowText;
	QWidget* subTabGeneral;
	QLabel* generalHeadLine;
	QGroupBox* genDispBox;
	QLabel* genText1;
	QLabel* genText2;
	MSpinBox* genDispX;
	MSpinBox* genDispY;
	QGroupBox* genRotBox;
	QLabel* genText3;
	QLabel* genText4;
	MSpinBox* genRot;

protected slots:
	/*!
	\author Franz Schmid
	\brief TabTools (Tools, Image Frame), Sets Y Scale value from X Scale value when chain is toggled
	*/
	virtual void toggleChain();
	/*!
	\author Franz Schmid
	\brief TabTools (Tools, Image Frame), Sets Y Scale value from X Scale value when X Scale value is changed
	*/
	virtual void hChange();
	/*!
	\author Franz Schmid
	\brief TabTools (Tools, Image Frame). Sets X Scale value from Y Scale value when Y Scale value is changed
	*/
	virtual void vChange();
	virtual void changeImageScalingFree(bool);
	virtual void changeImageScalingRatio(bool);
	/*!
	\author Franz Schmid
	\brief TabTools (Tools, Text frame), Sets the sample text in selected font in text frame preferences
	*/
	virtual void setSample();
	/*!
	\author Franz Schmid
	\brief TabTools (Tools), Raises widget for selected Tool properties
	*/
	virtual void setTool();
	virtual void setFillChar(int act);
	virtual void setCustomFillChar(const QString &txt);

protected:
	QHBoxLayout* tabToolsLayout;
	QVBoxLayout* buttonGroupToolsLayout;
	QGridLayout* subTabTextLayout;
	QGridLayout* subTabShapeLayout;
	QGridLayout* subTabLineLayout;
	QGridLayout* subTabImageLayout;
	QGridLayout* buttonGroup3Layout;
	QHBoxLayout* buttonGroup5Layout;
	QVBoxLayout* buttonGroupResLayout;
	QGridLayout* subTabPolygonLayout;
	QGridLayout* subTabZoomLayout;
	QGridLayout* subTabGeneralLayout;
	QGridLayout* subTabGeneralLayout2;
	QGridLayout* subTabGeneralLayout3;
	ScribusDoc* docu;
	double unitRatio;
	QString unit;
	int precision;

	/*! \brief True when is font sample allowed.
	See enableFontPreview() */
	bool fontPreview;

	void enableSignals(bool);
};
#endif
