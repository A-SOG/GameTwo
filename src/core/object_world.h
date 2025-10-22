#pragma once
#include"object_scrren.h"
//双向坐标转换：当设置世界位置时，自动更新渲染位置；
// 反之亦然
//自动同步：在update方法中自动同步世界位置和渲染位置
//场景关联：通过Game类获取当前场景进行坐标转换

class ObjectWorld :public ObjectScreen
{
protected:
	glm::vec2 position_ = glm::vec2(0, 0); // 世界位置
    virtual void init() override { type_ = ObjectType::OBJECT_WORLD; }

public:

    virtual void update(float dt) override;

    glm::vec2 getPosition() const { return position_; }
    void setPosition(const glm::vec2& position);
    virtual void setRenderPosition(const glm::vec2& render_position) override;
};