#include "menuitem.h"

using namespace lc::ui::api;

MenuItem::MenuItem(const char* menuItemName, kaguya::LuaRef callback, QWidget* parent)
    :
    QAction(menuItemName, parent),
    luaInterface(nullptr)
{
    this->setObjectName(menuItemName);
    callbacks.push_back(callback);
}

MenuItem::MenuItem(const char* menuItemName, QWidget* parent)
    :
    QAction(menuItemName, parent),
    luaInterface(nullptr)
{
    this->setObjectName(menuItemName);
}

std::string MenuItem::getLabel() {
    return this->text().toStdString();
}

void MenuItem::setLabel(const char* newLabel) {
    this->setText(newLabel);
}

void MenuItem::hide() {
    setVisible(false);
}

void MenuItem::show() {
    setVisible(true);
}

void MenuItem::setLuaInterface(LuaInterface* luaInterfaceIn, bool setCallbacks) {
    if (luaInterface != nullptr) {
        return;
    }

    luaInterface = luaInterfaceIn;

    // loop through all already added callbacks and connect them
    if (setCallbacks) {
        for (kaguya::LuaRef cb : callbacks)
        {
            luaInterface->luaConnect(this, "triggered(bool)", cb);
        }
    }
}

void MenuItem::addCallback(kaguya::LuaRef callback) {
    callbacks.push_back(callback);

    if (luaInterface != nullptr) {
        luaInterface->luaConnect(this, "triggered(bool)", callback);
    }
}
