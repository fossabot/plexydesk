#include "cpu.h"
#include "cpuwidget.h"
#include <QtCore>
#include<QtGui>


Cpu::Cpu(QObject * object):QObject(object)
{

}

Cpu::~Cpu()
{

}

QGraphicsItem * Cpu::backdrop()
{
return new  PlexyDesk::CpuWidget(QRectF(0,0,340,240),0);
}

Q_EXPORT_PLUGIN2(Cpu,Cpu)
#include "cpu.moc"