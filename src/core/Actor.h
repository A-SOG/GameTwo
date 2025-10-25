#pragma once
#include"object_world.h"
//速度向量：表示角色在x和y方向上的移动速度
//最大速度：限制角色移动的最大速度
//相关的getter和setter：用于访问和修改这些属性
class Stats;
class Actor :public ObjectWorld
{
protected:
    Stats* stats_ = nullptr; // 角色属性
    glm::vec2 velocity_ = glm::vec2(0, 0); // 速度
    float max_speed_ = 100.0f; // 最大速度大小

public:
    void move(float dt);
    glm::vec2 getVelocity() const { return velocity_; }
    void setVelocity(const glm::vec2& velocity) { velocity_ = velocity; }
    float getMaxSpeed() const { return max_speed_; }
    void setMaxSpeed(float max_speed) { max_speed_ = max_speed; }
    Stats* getStats() const { return stats_; }
    void setStats(Stats* stats) { stats_ = stats; }
    void takeDamage(float damage);
    bool getIsAlive() const;
};