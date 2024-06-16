#pragma once

#include <QQuickItem>

namespace QS
{
    class ApplicationWindow : public QQuickItem
    {
        Q_OBJECT
        QML_ELEMENT
    public:
        ApplicationWindow();
    };
    
} // namespace QS
