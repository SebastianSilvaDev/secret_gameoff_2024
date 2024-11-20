#include "Scene.h"

Scene::Scene(std::string in_scene_name) : m_name(in_scene_name)
{
}

std::string Scene::get_name() const
{
    return std::string();
}

void Scene::draw(tcod::Console *in_console)
{
}

void Scene::tick(double delta_time)
{
}
