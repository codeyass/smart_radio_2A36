#include "arduino.h"
#include <QDebug>

Arduino::Arduino()
{

    data="";
    arduino_port_name="";
    arduino_is_available=false;
    Serial=new QSerialPort;

}

int Arduino::connect_arduino()
{
    foreach(const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts())
    {
        if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier())
        {
            if(serial_port_info.vendorIdentifier()==arduino_uno_vendor_id && serial_port_info.productIdentifier()==arduino_uno_producy_id){

                arduino_is_available=true;
                arduino_port_name=serial_port_info.portName();

            }

        }

    }
    qDebug() << "arduino_port_name is: " <<arduino_port_name;
    if(arduino_is_available)
    {
      Serial->setPortName(arduino_port_name);
      if(Serial->open(QSerialPort::ReadWrite)){
          Serial->setBaudRate(QSerialPort::Baud9600);
          Serial->setDataBits(QSerialPort::Data8);
          Serial->setParity(QSerialPort::NoParity);
          Serial->setStopBits(QSerialPort::OneStop);
          Serial->setFlowControl(QSerialPort::NoFlowControl);
          return  0;

      }
      return 1;

    }

    return  -1;
}

int Arduino::close_arduino()
{
    if(Serial->isOpen()){
        Serial->close();
        return  0;
    }
    return  1;

}

QByteArray Arduino::read_from_arduino(){

    if(Serial->isReadable()){
        data=Serial->readAll();

    }
    return  data;
}

int Arduino::write_to_arduino(QByteArray d)
{
    if(Serial->isWritable())
    {
        Serial->write(d);
    }
    else {
        qDebug() <<"couldn't write to serial! " ;
    }

    return  0;
}

QString Arduino::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *Arduino::getserial()
{
   return Serial;
}
