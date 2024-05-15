import QtQuick

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Basic Calculator")
    
    property size mainWindowSize: Qt.size(root.width, root.height)
    onMainWindowSizeChanged: GlobalProps.setMainWindow(mainWindowSize)
    
    Item {
        id: viewport
        anchors.fill: parent
        
        Rectangle {
            id: test
            anchors.fill: parent
            color: "tomato"
        }
    }
}
