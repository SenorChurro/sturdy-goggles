cbuffer CBuff
{
	//later I will transpose the matrix before sending it to HLSL
	matrix transform;
};

float4 main(float3 pos : Position) : SV_Position
{
	return  mul(float4(pos, 1.0), transform);
}