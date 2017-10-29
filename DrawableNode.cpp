#include "DrawableNode.hpp"

using namespace engine::scene;

DrawableNode::DrawableNode(const utils::SharedPtr<Drawable> &geometry, Color color)
	: geometry(geometry), color(color)
{
}

DrawableNode::DrawableNode(const utils::SharedPtr<Drawable> &geometry, const Vector2<int16_t> &position, Color color)
	: geometry(geometry), position(position), color(color)
{
}

uint16_t DrawableNode::GetID() const
{
	return id;
}

Vector2<int16_t> DrawableNode::GetPosition() const
{
	return position;
}

void DrawableNode::SetPosition(const Vector2<int16_t> &position)
{
	this->position = position;
}

void DrawableNode::Draw(utils::SharedPtr<IScreen> &screen)
{
    screen->Draw(*geometry, position.x, position.y, color);

    for (auto &&child : children)
    {
		child->Draw(screen);
	}
}
