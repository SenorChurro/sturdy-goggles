struct VSOut
{
	float3 color : Color;
	float4 pos : SV_Position;
};

cbuffer CBuff
{
	//later I will transpose the matrix before sending it to HLSL
	matrix transform;
};

VSOut main(float2 pos : Position, float3 color : Color)
{
	VSOut vso;
	vso.pos = mul(float4(pos.x, pos.y, 0.0f, 1.0), transform);
	vso.color = color;

	return vso;
}