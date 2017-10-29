#include "Scene.hpp"

using namespace engine::scene;

using NodePtr = engine::utils::SharedPtr<INode>;

void Scene::AddNode(NodePtr node)
{
	nodes[node->GetID()] = node;
}

void Scene::RemoveNode(int id)
{
	nodes.erase(id);
}

void Scene::RemoveNode(const NodePtr &node)
{
	RemoveNode(node->GetID());
}

NodePtr Scene::GetNode(int id) const
{
	auto it = nodes.find(id);
	return it == nodes.end() ? nullptr : it->second;
}

void Scene::Draw(utils::SharedPtr<IScreen> screen)
{
	for (auto &&node : nodes)
	{
		node.second->Draw(screen);
	}
}
