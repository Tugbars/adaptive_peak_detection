#ifndef MES_SAVGOL_H
#define MES_SAVGOL_H

#include <stdint.h>
#include "mqs_def.h"
#include <stdbool.h>

typedef struct {
    uint8_t halfWindowSize;      // was m
    uint16_t targetPoint;        // was t
    uint8_t polynomialOrder;     // was n
    uint8_t derivativeOrder;     // was s
    float time_step;             // Changed from double to float
    uint8_t derivation_order;    // Adjusting to match the derivativeOrder type
} SavitzkyGolayFilterConfig;

typedef struct GramPolyKey {
    int dataIndex;
    uint8_t polynomialOrder;
    uint8_t derivativeOrder;
    uint8_t caseType; // 0 for central, 1 for border
} GramPolyKey;

typedef struct HashMapEntry {
    GramPolyKey key;
    float value;                 // Changed from double to float
    int isOccupied;
} HashMapEntry;

typedef struct {
    SavitzkyGolayFilterConfig conf;
    float* weights;              // Changed from double* to float*
    float dt;                    // Changed from double to float
} SavitzkyGolayFilter;

SavitzkyGolayFilter* SavitzkyGolayFilter_init(SavitzkyGolayFilterConfig conf);
void mes_savgolFilter(MqsRawDataPoint_t data[], size_t dataSize, uint8_t halfWindowSize, MqsRawDataPoint_t filteredData[], uint8_t polynomialOrder, uint8_t targetPoint, uint8_t derivativeOrder);


#endif // MES_SAVGOL_H
