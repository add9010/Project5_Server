#pragma once
#include <string>
#include "ClientSession.h"

class PlayerData {
public:
    PlayerData(const std::string& name, SOCKET socket);

    void PlayerCommitWrite(size_t bytesTransferred);
    void PlayerPostRecv();
    bool PlayerExtractPacket(Packet& packet);

    void setName(const std::string& name) { this->name = name; }
    void updatePosition(float x, float y) { posX = x; posY = y; }

    void processInit(Packet& packet);
    void processUpdate(Packet& packet);

    float getPosX() const { return posX; }
    float getPosY() const { return posY; }
    const std::string& getName() const { return name; }
    const ClientSession& getClientSession() const{ return session; }

    std::string name;
    float posX;
    float posY;
    ClientSession session;
};


