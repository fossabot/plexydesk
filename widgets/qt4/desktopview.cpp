#include "desktopview.h"
#include <backdropfactory.h>
#include <abstractplugininterface.h>
#include <QGLWidget>


namespace PlexyDesk
{
class  DesktopView::Private
{
    public:
    Private(){}
    ~Private(){}
    ExtensionProducer<BackdropInterface> fact;
    BackdropInterface * bIface ;
    WidgetInterface * widgets;       
    BackdropFactory * bgfact;
};

DesktopView::DesktopView ( QGraphicsScene * scene, QWidget * parent ):QGraphicsView(scene,parent),d(new Private)
{
       setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
       setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
       setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
       setAlignment(Qt::AlignLeft | Qt::AlignTop);
       d->bIface  = 0;
       d->widgets = 0;
       QString defaults = PluginLoader::getInstance()->listPlugins("Desktop").first();
       d->bIface = (BackdropInterface*)PluginLoader::getInstance()->instance(defaults);
}

DesktopView::~DesktopView()
{
    delete d;
}

void DesktopView::addExtension(const QString& name)
{
        d->widgets = (WidgetInterface*) PluginLoader::getInstance()->instance(name);
        if (d->widgets)
        scene()->addItem(d->widgets->item());
}

void DesktopView::drawBackground ( QPainter * painter, const QRectF & rect )
{
    painter->save();
    painter->setClipRect(rect);
    if(d->bIface){
  	d->bIface->render(painter,QRectF(rect.x(),rect.y(),rect.width(),rect.height()));
    }
    painter->restore();
}


}
#include "desktopview.moc"
