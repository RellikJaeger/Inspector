//
// Created by Paker on 04/04/20.
//

#ifndef INSPECTOR_CUSTOMPLUGIN_H
#define INSPECTOR_CUSTOMPLUGIN_H

#include <map>
#include <string>
#include <vector>
#include <functional>

#include "Router.h"

typedef std::function<std::string()> PluginAction;
typedef std::function<std::string(const Params &)> PluginAPIAction;

struct PluginMeta {
    std::string key, name;
    bool live;
};

void to_json(nlohmann::json &j, const PluginMeta &p);

class CustomPlugin {
private:
    Router &router;
    std::vector<PluginMeta> plugins;
    std::map<std::string, PluginAction> actions;

    void addPlugin(const std::string &key, const std::string &name, PluginAction action, bool live);

public:
    CustomPlugin(Router &router);

    Response execute(PluginAction executor);

    void addPlugin(const std::string &key, const std::string &name, PluginAction action);
    void addPluginAPI(const std::string &method, const std::string &path, PluginAPIAction action);
    void addLivePlugin(const std::string &key, const std::string &name, PluginAction action);
};

#endif //INSPECTOR_CUSTOMPLUGIN_H
