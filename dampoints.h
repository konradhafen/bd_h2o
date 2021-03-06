#ifndef DAMPOINTS_H
#define DAMPOINTS_H

#include "ogrsf_frmts.h"
#include "ogr_core.h"
#include "ogr_api.h"
#include "geometry.h"
#include "statistics.h"
#include "raster.h"
#include "raster_beaverpond.h"

class DamPoints
{
public:
    DamPoints(const char *demPath, const char *bratPath, const char *facPath, const char *outDirPath, double modCap);
    DamPoints(const char *demPath, const char *bratPath, const char *facPath, const char *statPath, const char *outDirPath, double modCap);
    DamPoints(const char *demPath, const char *bratPath, const char *facPath, const char *statPath, const char *outDirPath, double modCap, int nDamPlaceType);
    DamPoints(const char *demPath, const char *bratPath, const char *facPath, const char *statPath, const char *outDirPath, double modCap, const char *exPath, int type);

    void init(const char *bratPath);
    void init(const char *bratPath, const char *exPath, int type);

    void compareArea(const char *damsIn, const char *csvOut);
    void createDamPoints_BRAT(OGRLayer *pBratLyr, OGRLayer *pDamsLyr);
    void createDamPoints_BRATcomplex(OGRLayer *pBratLyr, OGRLayer *pDamsLyr);
    void createDamPoints_BRATcomplex100(OGRLayer *pBratLyr, OGRLayer *pDamsLyr);
    void createDamPoints_Copy(OGRLayer *pBratLyr, OGRLayer *pDamsLyr, OGRLayer *pExLyr);
    void createDamPoints_CopyLoc(OGRLayer *pBratLyr, OGRLayer *pDamsLyr, OGRLayer *pExLyr);
    void createDamPoints_Heights(OGRLayer *pBratLyr, OGRLayer *pDamsLyr, OGRLayer *pExLyr);
    void createDamPoints_HeightsLoc(OGRLayer *pBratLyr, OGRLayer *pDamsLyr, OGRLayer *pExLyr);
    void createFields(OGRLayer *pLayer);
    QString getBratDir();
    QString getBratName();
    bool getSuccess();
    const char* getDemPath();
    const char* getLayerName();
    const char* getOutDirPath();
    void loadDriver();
    void setBratCapacity(double capacity);
    void setBratPath(QString path);
    void setBratName(QString name);
    void setDemPath(const char *demPath);
    void setDamHeights(OGRFeature *pFeat, double low, double mid, double high, double max);
    void setFacPath(const char *facPath);
    void setFieldValues(OGRFeature *pFeat, int bratID, double groundElev, double slope, double azimuth, double ptX, double ptY);
    void setOutDir(const char *outDirPath);
    void sortByCapacity(OGRLayer *pBratLyr);

    static bool setPondAttributes(OGRFeature *pFeat, double lowarea, double midarea, double hiarea, double lowvol, double midvol, double hivol);

private:
    OGRSFDriver *m_pDriverShp;

    int m_nDamPlace;
    double m_modCap, m_meanDamHeight, m_confHi, m_confLo;
    const char *m_outDir, *m_layerName, *m_demPath, *m_facPath, *m_statPath;
    QString m_qsBratDir, m_qsBratName;
    QVector<double> m_qvCapacityRank, m_qvMaxDams;
    QVector<int> m_qvBratFID;
    bool m_success = true;
};

#endif // DAMPOINTS_H
