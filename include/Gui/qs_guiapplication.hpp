#pragma once

#include <QGuiApplication>

namespace QS
{
    class GuiApplication : public QGuiApplication
    {
    public:
        explicit GuiApplication(int &, char **);
    };
    
} // namespace QS