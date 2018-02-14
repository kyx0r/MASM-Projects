
CUSTOM_VERTEX STRUCT 
	x	REAL4 ?
	y	REAL4 ?
	z	REAL4 ?
	nx	REAL4 ?
	ny	REAL4 ?
	nz	REAL4 ?
	u	REAL4 ?
	v	REAL4 ?
CUSTOM_VERTEX ENDS

.data

; Here's the cube. First x,y,z, then the normal, and then the two texture coordinates.
vertexes 	CUSTOM_VERTEX 	<-5.0,-5.0,-5.0, 0.0, 0.0,-1.0, 0.0, 1.0>
		CUSTOM_VERTEX	<-5.0, 5.0,-5.0, 0.0, 0.0,-1.0, 0.0, 0.0>
		CUSTOM_VERTEX	< 5.0,-5.0,-5.0, 0.0, 0.0,-1.0, 1.0, 1.0>
		CUSTOM_VERTEX	< 5.0, 5.0,-5.0, 0.0, 0.0,-1.0, 1.0, 0.0>
		CUSTOM_VERTEX	< 5.0,-5.0,-5.0, 0.0, 0.0,-1.0, 1.0, 1.0>
		CUSTOM_VERTEX	<-5.0, 5.0,-5.0, 0.0, 0.0,-1.0, 0.0, 0.0>
		CUSTOM_VERTEX	< 5.0,-5.0, 5.0, 0.0, 0.0, 1.0, 0.0, 1.0>
		CUSTOM_VERTEX	< 5.0, 5.0, 5.0, 0.0, 0.0 ,1.0, 0.0, 0.0>
		CUSTOM_VERTEX	<-5.0,-5.0, 5.0, 0.0, 0.0, 1.0, 1.0, 1.0>
		CUSTOM_VERTEX	<-5.0, 5.0, 5.0, 0.0, 0.0, 1.0, 1.0, 0.0>
		CUSTOM_VERTEX	<-5.0,-5.0, 5.0, 0.0, 0.0, 1.0, 1.0, 1.0>
		CUSTOM_VERTEX	< 5.0, 5.0, 5.0, 0.0, 0.0, 1.0, 0.0, 0.0>
		CUSTOM_VERTEX	<-5.0,-5.0, 5.0,-1.0, 0.0, 0.0, 0.0, 1.0>
		CUSTOM_VERTEX	<-5.0, 5.0, 5.0,-1.0, 0.0, 0.0, 0.0, 0.0>
		CUSTOM_VERTEX	<-5.0,-5.0,-5.0,-1.0, 0.0, 0.0, 1.0, 1.0>
		CUSTOM_VERTEX	<-5.0, 5.0,-5.0,-1.0, 0.0, 0.0, 1.0, 0.0>
		CUSTOM_VERTEX	<-5.0,-5.0,-5.0,-1.0, 0.0, 0.0, 1.0, 1.0>
		CUSTOM_VERTEX	<-5.0, 5.0, 5.0,-1.0, 0.0, 0.0, 0.0, 0.0>
		CUSTOM_VERTEX	< 5.0,-5.0,-5.0, 1.0, 0.0, 0.0, 0.0, 1.0>
		CUSTOM_VERTEX	< 5.0, 5.0,-5.0, 1.0, 0.0, 0.0, 0.0, 0.0>
		CUSTOM_VERTEX	< 5.0,-5.0, 5.0, 1.0, 0.0, 0.0, 1.0, 1.0>
		CUSTOM_VERTEX	< 5.0, 5.0, 5.0, 1.0, 0.0, 0.0, 1.0, 0.0>
		CUSTOM_VERTEX	< 5.0,-5.0, 5.0, 1.0, 0.0, 0.0, 1.0, 1.0>
		CUSTOM_VERTEX	< 5.0, 5.0,-5.0, 1.0, 0.0, 0.0, 0.0, 0.0>
		CUSTOM_VERTEX	< 5.0,-5.0,-5.0, 0.0,-1.0, 0.0, 0.0, 1.0>
		CUSTOM_VERTEX	< 5.0,-5.0, 5.0, 0.0,-1.0, 0.0, 0.0, 0.0>
		CUSTOM_VERTEX	<-5.0,-5.0,-5.0, 0.0,-1.0, 0.0, 1.0, 1.0>
 		CUSTOM_VERTEX	<-5.0,-5.0, 5.0, 0.0,-1.0, 0.0, 1.0, 0.0>
		CUSTOM_VERTEX	<-5.0,-5.0,-5.0, 0.0,-1.0, 0.0, 1.0, 1.0>
		CUSTOM_VERTEX	< 5.0,-5.0, 5.0, 0.0,-1.0, 0.0, 0.0, 0.0>
 		CUSTOM_VERTEX	<-5.0, 5.0,-5.0, 0.0, 1.0, 0.0, 0.0, 1.0>
 		CUSTOM_VERTEX	<-5.0, 5.0, 5.0, 0.0, 1.0, 0.0, 0.0, 0.0>
 		CUSTOM_VERTEX	< 5.0, 5.0,-5.0, 0.0, 1.0, 0.0, 1.0, 1.0>
  		CUSTOM_VERTEX	< 5.0, 5.0, 5.0, 0.0, 1.0, 0.0, 1.0, 0.0>
 		CUSTOM_VERTEX	< 5.0, 5.0,-5.0, 0.0, 1.0, 0.0, 1.0, 1.0>
		CUSTOM_VERTEX	<-5.0, 5.0, 5.0, 0.0, 1.0, 0.0, 0.0, 0.0>	
