#pragma once
#include"object_scrren.h"
#include"../affilicate/collider.h"
//双向坐标转换：当设置世界位置时，自动更新渲染位置；
// 反之亦然
//自动同步：在update方法中自动同步世界位置和渲染位置
//场景关联：通过Game类获取当前场景进行坐标转换

class ObjectWorld :public ObjectScreen
{
protected:
	glm::vec2 position_ = glm::vec2(0, 0); // 世界位置
   
    Collider* collider_ = nullptr;
public:
    virtual void init() override { type_ = ObjectType::OBJECT_WORLD; }
    virtual void update(float dt) override;

   virtual glm::vec2 getPosition() const override{ return position_; }
    void setPosition(const glm::vec2& position);
    virtual void setRenderPosition(const glm::vec2& render_position) override;
        
    Collider* getCollider() { return collider_; }
    void setCollider(Collider* collider) { collider_ = collider; }
    virtual void takeDamage(float) { return; }

};