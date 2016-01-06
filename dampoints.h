#ifndef DAMPOINTS_H
#define DAMPOINTS_H

#include "ogrsf_frmts.h"
#include "ogr_core.h"
#include "ogr_api.h"
#include "geometry.h"
#include "random.h"
#include "raster.h"

class DamPoints
{
public:
    DamPoints(const char *pointsPath);
    DamPoints(const char *demPath, const char *bratPath, const char *outDirPath, double modCap);

    void init(const char *bratPath);

    void createDamPoints_BRAT(OGRLayer *pBratLyr, OGRLayer *pDamsLyr);
    void createDamPoints_Copy();
    void createFields(OGRLayer *pLayer);
    void loadDriver();
    void setBratCapacity(double capacity);
    void setDemPath(const char *demPath);
    void setFieldValues(OGRFeature *pFeat, double damElev, double groundElev, double slope, double azimuth, double ptX, double ptY);
    void setOutDir(const char *outDirPath);

private:
    OGRSFDriver *m_pDriverShp;

    double m_modCap;
    const char *m_outDir, *m_layerName, *m_demPath;
};

#endif // DAMPOINTS_H
