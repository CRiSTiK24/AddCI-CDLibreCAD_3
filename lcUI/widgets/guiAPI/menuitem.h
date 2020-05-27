#pragma once

#include <luainterface.h>

#include <QAction>

namespace lc
{
    namespace ui
    {
        namespace api
        {
            class MenuItem : public QAction
            {
                Q_OBJECT

            public:
                MenuItem(const char* menuItemName, kaguya::LuaRef callback, QWidget* parent = nullptr);

                MenuItem(const char* menuItemName, QWidget* parent = nullptr);

                std::string getLabel();

                void setLabel(const char* newLabel);

                void addCallback(kaguya::LuaRef callback);

                void hide();

                void show();

                void setLuaInterface(LuaInterface* luaInterfaceIn, bool setCallbacks = true);

            private:
                LuaInterface* luaInterface;
                std::vector<kaguya::LuaRef> callbacks;
            };
        }
    }
}
