#ifndef STORAGEMODEL_H
#define STORAGEMODEL_H

#include "dampolygons.h"
#include "reachlines.h"
#include "raster_beaverpond.h"

class StorageModel
{
public:
    StorageModel(const char *bratPath, const char *outPath, const char *demPath, const char *fdirPath, const char *facPath, double capacity);

    void init(const char *bratPath, const char *outPath, const char *demPath, const char *fdirPath, const char *facPath, double capacity);

    void calcFinalWSE(DamPolygons pondExtents);
    void calcSurfaceWSE();
    void cleanOutDir();
    void createHandInputs();
    void run();
    void runFromPoints(const char *damsIn, const char *csvOut);
    void setOutputPaths(DamPolygons pondExtents);

private:
    const char *m_bratPath, *m_outPath, *m_demPath, *m_fdirPath, *m_facPath;
    QVector<QString> m_qvPondPaths, m_qvSurfaceDepthPaths, m_qvSurfaceWSEPaths, m_qvWSEPaths, m_qvHandIn;
    double bratCap;
};

#endif // STORAGEMODEL_H
