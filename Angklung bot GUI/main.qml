import QtQuick 2.12
import QtQuick.Window 2.13
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4
import QtQuick.Extras.Private 1.0


Window {
	id : root
	width: 800
	maximumWidth : 800
	minimumWidth : 800
    height: 650
	maximumHeight : 650
	minimumHeight : 650
	title:"Ardumeka Angklung-Bot Controller"
	color : "#111111"
    visible: true
    //flags: Qt.WindowMaximized //Qt.Dialog
	
	
	
	
	
	
	Image{
		id : ardumeka
		x : 40
		y : 10
		width : 120
		height : 140
		source : "ardumeka.png"
		
	}
	
	Image{
		x : 650
		y : 20
		width : 120
		height : 120
		source : "angklung.png"
		
	}
	
	
	Rectangle{
		
		anchors.horizontalCenter: parent.horizontalCenter
		y:20
		width : 450
		height : 120
		color : "#04b6f0"
		border.color: "white"
		border.width: 5
	
	Text{
		
		anchors.horizontalCenter: parent.horizontalCenter
		y: 15
		//anchors.verticalCenter: parent.verticalCenter
		width : 400
		text : "Ardumeka Angklung-Bot Controller"
		wrapMode: Text.WordWrap 
		horizontalAlignment: Text.AlignHCenter//Text.AlignJustify
		color : "#111111"
		font.pixelSize : 25
	}
	
	Text{
		
		anchors.horizontalCenter: parent.horizontalCenter
		y: 60
		//anchors.verticalCenter: parent.verticalCenter
		width : 400
		text : "Written By : Ajang Rahmat and Muhammad Husni"
		wrapMode: Text.WordWrap 
		horizontalAlignment: Text.AlignHCenter//Text.AlignJustify
		color : "#111111"
		font.pixelSize : 18
	}
	
	
	
	}
	
	Rectangle {
	y:200
	anchors.horizontalCenter: parent.horizontalCenter
	width : 650
	color : "transparent"
	
	Rectangle{
		//1
		id : button1
		x: 0
		y: 0
		width : 40
		height : 220
		color : "#d84860"
		border.color: "white"
		border.width: 5
		
		Text{
		x: (parent.width-10)/2
		y: (parent.height-30)/2
		text : "1"
		color : "#111111"
		font.pixelSize : 24
	}
		
		
	}
	
	
	Rectangle{
		//2
		id : button2
		x: 90
		y: 0
		width : 40
		height : 220
		color : "#122e55"
		border.color: "white"
		border.width: 5
	
	Text{
		x: (parent.width-10)/2
		y: (parent.height-30)/2
		text : "2"
		color : "#111111"
		font.pixelSize : 24
	}
	
	}
	
	
	
	Rectangle{
		//3
		id : button3
		x: 180
		y: 0
		width : 40
		height : 220
		color : "#d84860"
		border.color: "white"
		border.width: 5
	
	
	Text{
		x: (parent.width-10)/2
		y: (parent.height-30)/2
		text : "3"
		color : "#111111"
		font.pixelSize : 24
	}
	
	
	}
	
	
	Rectangle{
		//4
		id : button4
		x: 270
		y: 0
		width : 40
		height : 220
		color : "#122e55"
		border.color: "white"
		border.width: 5
	
	Text{
		x: (parent.width-10)/2
		y: (parent.height-30)/2
		text : "4"
		color : "#111111"
		font.pixelSize : 24
	}
	
	
	}
	
	
	Rectangle{
		//L1
		id : l1
		x: 360
		y: 0
		width : 40
		height : 220
		color : "#122e55"
		border.color: "white"
		border.width: 5
	
	
		Text{
		x: (parent.width-10)/2
		y: (parent.height-30)/2
		width : parent.width
		text : "5"
		color : "#111111"
		font.pixelSize : 24
	}
	
	}
	
	
	Rectangle{
		//R1
		id : r1
		x: 450
		y: 0
		width : 40
		height : 220
		color : "#d84860"
		border.color: "white"
		border.width: 5
		
		Text{
		x: (parent.width-10)/2
		y: (parent.height-30)/2
		text : "6"
		color : "#111111"
		font.pixelSize : 24
	}
		
		
	}
	
	

	Rectangle{
		//L2
		id : l2
		x: 540
		y: 0
		width : 40
		height : 220
		color : "#d84860"
		border.color: "white"
		border.width: 5
	
	
		Text{
		x: (parent.width-10)/2
		y: (parent.height-30)/2
		text : "7"
		color : "#111111"
		font.pixelSize : 24
	}
	
	}
	
	
	
	Rectangle{
		//R2
		id : r2
		x: 630
		y: 0
		width : 40
		height : 220
		color : "#122e55"
		border.color: "white"
		border.width: 5
	
		Text{
		x: (parent.width-10)/2
		y: (parent.height-30)/2
		text : "8"
		color : "#111111"
		font.pixelSize : 24
	}
	
	
	}
	
	
	
	
	
	
	
	
	
	
	}
	
	
	
	
	
	Rectangle {
	x:20
	y:450
	width : 350
	height : 180
	color : "transparent"
	border.width : 3
	border.color : "white"
	
	
	Text {
			x : 10
			y : 10		
			text: "ANGKLUNG USB PORT :"
			font.family: "Helvetica"
			font.pointSize: 14
			color: "white"
		}
		
	ComboBox {
		id : cb1
		x: 10
		y : 45
		width : 200

	}
	
	Button {
		id: connect
		x :230
		y :40
		width : 100
		height : 100
		text: ""
		font.pixelSize : 20
		
		Rectangle{
			id:connect_color
			width : parent.width
			height: parent.height
			color:"#df1c39"
			
			Image{
			width : parent.width
			height : parent.height
			source : "connect logo.png"
			
			}
			
			
		}
		
		onClicked:{
			if(connect_color.color == "#df1c39"){
				connect_color.color = "#04f8fa"
				backend.connection("connected")
				backend.port_number(cb1.currentText)
				//table.baudrate(cb2.currentText)
			}else
				if(connect_color.color == "#04f8fa"){
				connect_color.color = "#df1c39" 
				backend.connection("disconnected")
				}
		}
		
	
			
		
		
		
		
	}
	
	
	
	
	
	}
	
	Rectangle {
	x:400
	y:450
	width : 350
	height : 180
	color : "#01ccf5"
	border.width : 3
	border.color : "white"
	
	Text {
			x : 10
			y : 10		
			text: "VOICE SENSOR ACTIVATION :"
			font.family: "Helvetica"
			font.pointSize: 14
			color: "black"
		}
	
	}
	
	
	
	Timer{
		id: gui_timer
		interval: 50
		repeat: true
		running: true
		onTriggered: {
			
			
			button1.color = backend.button1_color()
			button2.color = backend.button2_color()
			button3.color = backend.button3_color()
			button4.color = backend.button4_color()
			l1.color = backend.button_L1_color()
			l2.color = backend.button_L2_color()
			r1.color = backend.button_R1_color()
			r2.color = backend.button_R2_color()
			
			cb1.model = backend.port()
		
		}
		
	}
	
	
	
	
	
}













