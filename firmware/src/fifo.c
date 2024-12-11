#include "fifo.h"

void bfifo_init(BFIFO *fifo, uint8_t *buffer, unsigned int elemno)
{
	fifo->pIn = fifo->pOut = fifo->pStart = buffer;
	fifo->pEnd = buffer + elemno;
}

int bfifo_put(BFIFO *fifo, uint8_t src)
{
	uint8_t *pinold, *pinnew;

	pinold = pinnew = fifo->pIn;
	if (++pinnew == fifo->pEnd) pinnew = fifo->pStart;
	if (pinnew == fifo->pOut) return -1; // fifo full

	*pinold = src;
	fifo->pIn = pinnew;
	return src;
}

int bfifo_get(BFIFO *fifo)
{
	uint8_t *pout, b;

	pout = fifo->pOut;
	if (pout == fifo->pIn) return -1; // fifo empty

	b = *pout;
	if (++pout == fifo->pEnd) pout = fifo->pStart;
	fifo->pOut = pout;
	return b;
}

int bfifo_full(BFIFO *fifo)
{
	uint8_t *pin;

	pin = fifo->pIn;
	if (++pin == fifo->pEnd) pin = fifo->pStart;
	if (pin == fifo->pOut) return -1; /* fifo full */
	return 0;
}

int bfifo_empty(BFIFO *fifo)
{
	if (fifo->pOut == fifo->pIn) return -1; /* fifo empty */
	return 0;
}
