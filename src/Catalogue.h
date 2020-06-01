
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

#include <vector>
#include "Sensor.h"
#include "Cleaner.h"

class Catalogue
{

public:
    float getAverageQuality(float latitude, float longitude, float radius, string begin, string end="2021-01-01");
    void addCleaner(Cleaner cleaner);
    Cleaner removeCleaner(string cleanerId);
    void addSensor(string id, float latitude, float longitude, string description);
    void addCleaner(string id, float latitude, float longitude, string begin, string end);
    void addMeasure(Measure uneMeasure);

// constructeur - déstructeur
    Catalogue();
    Catalogue(string measureFile, string sensorFile, string cleanerFile);
    Catalogue ( const Catalogue & unCatalogue );
    virtual ~Catalogue ();
//getter
    vector<Sensor> getSensorList();
    list<Measure> getMeasureList();
    list<Cleaner> getCleanerList();
    Cleaner GetCleanerById(string id);


protected:

//setter
    void setMeasures(string fileName);
    void setSensors (string fileName);
    void setCleaners (string fileName);
    list<Measure> setIndividualMeasures(string fileName);

    list<Measure> measureList;
    vector<Sensor> sensorList;
    list<Cleaner> cleanerList;
    int nbMeasure;
    int nbSensor;
    int nbCleaner;

};

#endif // CATALOGUE_H
