#pragma once
#include"core/scene.h"

class Player;
class SceneMain : public Scene
{
private:

    void renderBackground();

    Player* player_ = nullptr; // 玩家
public:
    SceneMain() = default;
    virtual ~SceneMain() = default;

    virtual void init() override;
    virtual void handleEvents(SDL_Event& event) override;
    virtual void update(float dt) override;
    virtual void render() override;
    virtual void clean() override;

};