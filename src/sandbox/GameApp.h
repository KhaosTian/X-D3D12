#pragma once

#include "GameCore.h"

using GameCore::IGameApp;

class GameApp: public IGameApp {
public:
    GameApp(void) = default;

    virtual void Startup() override;
    virtual void Cleanup() override;
    virtual void Update(float deltaT) override;
    virtual void RenderScene() override;
};
