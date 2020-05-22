/******** author Zakaria *********/
#if ! defined ( MEASURE_H )
#define MEASURE_H

#include <string>
#include <list>

#include "Sensor.h"
#include "Catalogue.h"

using namespace std;

class Measure
{

public:
    Sensor getSensor(list<Sensor> data);
    float getValue();
    void detectFraud(list<Sensor> sdata, list<Measure> mdata);
    Measure ( const Measure & unMeasures );
    Measure( string ts, string sID, string attID, float val, bool isF);
    Measure();
    virtual ~Measure();

protected:

    string timestamp;
    string sensorID;
    string attributeId;
    float value;
    bool isFake;

};

#endif // MEASURES_H