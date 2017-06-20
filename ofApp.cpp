#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("20170620");
	ofEnableDepthTest();
		
	this->icoSphere.setRadius(300);	
	this->icoSphere.setResolution(3);

	this->light.setAreaLight(2048, 2048);
	this->light.setAmbientColor(ofFloatColor(0.0, 0.0, 0.0, 1.0));
	this->light.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
	this->light.setSpecularColor(ofFloatColor(1.0, 0.0, 0.0));

}

//--------------------------------------------------------------
void ofApp::update(){
	this->light.setPosition(this->cam.getPosition().normalize() * 2048);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofEnableLighting();
	this->light.enable();

	cam.begin();

	ofRotateY(ofGetFrameNum() % 360);

	float noise_value;
	vector<ofMeshFace> triangles = icoSphere.getMesh().getUniqueFaces();

	ofVec3f faceNormal;
	ofColor c;
	for (int i = 0; i < triangles.size(); i++) {
		faceNormal = triangles[i].getFaceNormal();
		noise_value = ofNoise(i * 0.0025, ofGetFrameNum() * 0.01);
		for (int j = 0; j < 3; j++) {
			if (noise_value > 0.75) {
				triangles[i].setVertex(j, triangles[i].getVertex(j).normalized() * ofMap(noise_value, 0.75, 1.0, 0.5, 1.5) * 300);
			}
			else {
				triangles[i].setVertex(j, triangles[i].getVertex(j).normalized() * (300 * 0.5));
			}
		}

	}

	this->icoSphere.getMesh().setFromTriangles(triangles);

	//this->icoSphere.draw();
	this->icoSphere.drawWireframe();

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
