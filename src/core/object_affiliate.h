#pragma once
#include"object_scrren.h"

class ObjectAffiliate:public Object
{
protected:
	ObjectScreen* parent_ = nullptr;//父节点
	glm::vec2 offset_ = glm::vec2(0, 0);//相对便宜
	glm::vec2 size_ = glm::vec2(0, 0);//大小
	Anchor anchor_ = Anchor::CENTER;
public:
	//得到和改变数据
	void setOffsetByAnchor(Anchor anchor);
	ObjectScreen* getParent()const { return parent_; }
	void setParent(ObjectScreen* parent) { parent_ = parent; }
	glm::vec2 getOffset()const { return offset_; }
	void setOffset(const glm::vec2& offset) { offset_ = offset; }
	glm::vec2 getSize() const { return size_; }
	void setSize(const glm::vec2& size);
	void setScale(float scale);
	Anchor getAnchor()const { return anchor_; }
	void setAnchor(Anchor anchor) { anchor_ = anchor; }
};