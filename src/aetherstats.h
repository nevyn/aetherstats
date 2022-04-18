#pragma once

class AetherStats
{
public:
    
    void main();
    void connect(const char* host);
private:
    bool autoconnect;
    char destination[255] = "";
};
