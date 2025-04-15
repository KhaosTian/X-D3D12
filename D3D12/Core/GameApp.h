#pragma once

#include "GameCore.h"

class GameApp: public GameCore::IGameApp {
public:
    GameApp(void) = default;

    virtual void Startup() override;
    virtual void Cleanup() override;
    virtual void Update(float deltaT) override;
    virtual void RenderScene() override;
};
