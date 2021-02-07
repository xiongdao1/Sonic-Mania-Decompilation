#ifndef MATH_H
#define MATH_H

struct Vector2 {
    int x;
    int y;
};

#define MEM_ZERO(x)  memset(&(x), 0, sizeof((x)))
#define MEM_ZEROP(x) memset((x), 0, sizeof(*(x)))

extern int sinVal1024[0x400];
extern int cosVal1024[0x400];

extern int ATanVal1024[0x400];
extern int ASinVal1024[0x400];
extern int ACosVal1024[0x400];

extern int sinVal512[0x200];
extern int cosVal512[0x200];

extern int ATanVal512[0x200];
extern int ASinVal512[0x200];
extern int ACosVal512[0x200];

extern int sinVal256[0x100];
extern int cosVal256[0x100];

extern int ATanVal256[0x100];
extern int ASinVal256[0x100];
extern int ACosVal256[0x100];

extern byte atanVal256[0x100 * 0x100];

// Setup angles
void CalculateTrigAngles();

inline int sin1024(int angle)
{
    if (angle < 0)
        angle = 0x400 - angle;
    angle &= 0x3FF;
    return sinVal1024[angle];
}

inline int cos1024(int angle)
{
    if (angle < 0)
        angle = 0x400 - angle;
    angle &= 0x3FF;
    return cosVal1024[angle];
}

inline int sin512(int angle)
{
    if (angle < 0)
        angle = 0x200 - angle;
    angle &= 0x1FF;
    return sinVal512[angle];
}

inline int cos512(int angle)
{
    if (angle < 0)
        angle = 0x200 - angle;
    angle &= 0x1FF;
    return cosVal512[angle];
}

inline int sin256(int angle)
{
    if (angle < 0)
        angle = 0x100 - angle;
    angle &= 0xFF;
    return sinVal256[angle];
}

inline int cos256(int angle)
{
    if (angle < 0)
        angle = 0x100 - angle;
    angle &= 0xFF;
    return cosVal256[angle];
}

inline int aTan1024(short angle) { return ATanVal1024[angle & 0x3FF]; }

inline int aSin1024(int angle)
{
    if (angle > 0x3FF)
        return 0;
    if (angle < 0)
        return -ASinVal1024[-angle];
    return ASinVal1024[angle];
}
inline int aCos1024(int angle)
{
    if (angle > 0x3FF)
        return 0;
    if (angle < 0)
        return -ACosVal1024[-angle];
    return ACosVal1024[angle];
}

inline int aTan512(short angle) { return ATanVal512[angle & 0x1FF]; }
inline int aSin512(int angle)
{
    if (angle > 0x1FF)
        return 0;
    if (angle < 0)
        return -ASinVal512[-angle];
    return ASinVal512[angle];
}
inline int aCos512(int angle)
{
    if (angle > 0x1FF)
        return 0;
    if (angle < 0)
        return -ACosVal512[-angle];
    return ACosVal512[angle];
}
inline int aTan256(byte angle) { return ATanVal256[angle]; }
inline int aSin256(int angle)
{
    if (angle > 0xFF)
        return 0;
    if (angle < 0)
        return -ASinVal256[-angle];
    return ASinVal256[angle];
}
inline int aCos256(int angle)
{
    if (angle > 0xFF)
        return 0;
    if (angle < 0)
        return -ACosVal256[-angle];
    return ACosVal256[angle];
}

// Get Arc Tan value
byte ArcTanLookup(int x, int y);

extern uint randKey;

inline void setRandKey(int key) { randKey = key; }

inline int random(int min, int max)
{
    int v2;        
    uint v4; 
    int v5;  

    v2      = 1103515245 * randKey + 12345;
    v4      = 1103515245 * v2 + 12345;
    randKey = 1103515245 * v4 + 12345;
    v5      = ((((((v2 >> 16) & 0x7FF) << 10) ^ (v4 >> 16) & 0x7FF) << 10) ^ (randKey >> 16) & 0x7FF);
    if (min >= max)
        return max + (v5 % (min - max));
    else
        return min + (v5 % (max - min));
}

inline int random2(int min, int max, int *randKey)
{
    int v4;
    int v5;
    int v6;
    int v7;
    int v8;
    int v9;

    if (!randKey)
        return 0;
    v4       = 1103515245 * *randKey + 12345;
    v5       = v4;
    v6       = 1103515245 * v4 + 12345;
    v7       = (((v5 >> 16) & 0x7FF) << 10) ^ (v6 >> 16) & 0x7FF;
    v8       = 1103515245 * v6 + 12345;
    *randKey = v8;
    v9       = (v7 << 10) ^ (v8 >> 16) & 0x7FF;
    if (min >= max)
        return max + (v9 % (min - max));
    else
        return min + (v9 % (max - min));
}

#endif // !MATH_H