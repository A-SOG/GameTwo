#pragma once
#include"object.h"
//ObjectScreen类的主要作用是管理对象在屏幕上的渲染位置，
// 这对于UI元素或者直接在屏幕坐标系中定位的对象非常有用。
class ObjectScreen :public Object
{
protected:
	glm::vec2 render_position_ = glm::vec2(0, 0);//渲染屏幕位置
	virtual void init() override { type_ = ObjectType::OBJECT_SCREEN; }

public:
	//得到数据
	glm::vec2 getRenderPosition()const { return render_position_; };
	virtual void setRenderPosition(const glm::vec2& render_position)
	{
		render_position_ = render_position;

	}
	virtual glm::vec2 getPosition()const { return glm::vec2(0); }
};