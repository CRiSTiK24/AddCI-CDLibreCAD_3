#pragma once

#include <QWidget>
#include <QTabWidget>

#include <widgets/guiAPI/toolbartab.h>

namespace lc {
    namespace ui {
        namespace widgets {
            class CustomizeParentTab : public QTabWidget
            {
            public:
                CustomizeParentTab(lc::ui::api::ToolbarTab* toolbarTab, QWidget* parent = nullptr);

                CustomizeParentTab(QString label , QWidget* parent = nullptr);

            private:
                void init();

            public slots:
                void addGroupTab();

                void groupTabClosed(int index);
            };
        }
    }
}
