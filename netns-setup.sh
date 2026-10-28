#!/bin/bash
# Test bench for ft_malcolm: target namespace + veth 
# Usage : sudo ./netns-setup.sh up | down

set -e

NS="ns_target"
VETH_HOST="veth-malcolm"
VETH_NS="veth-target"
IP_HOST="10.0.0.1/24"
IP_NS="10.0.0.2/24"

up() {
	ip netns add "$NS"
	ip link add "$VETH_HOST" type veth peer name "$VETH_NS"
	ip link set "$VETH_NS" netns "$NS"

	ip addr add "$IP_HOST" dev "$VETH_HOST"
	ip link set "$VETH_HOST" up

	ip netns exec "$NS" ip addr add "$IP_NS" dev "$VETH_NS"
	ip netns exec "$NS" ip link set "$VETH_NS" up
	ip netns exec "$NS" ip link set lo up

	echo "Bench up."
	echo -n "MAC $VETH_HOST (you)\t: "
	ip link show "$VETH_HOST" | awk '/ether/ {print $2}'
	echo -n "MAC $VETH_NS (target)\t: "
	ip netns exec "$NS" ip link show "$VETH_NS" | awk '/ether/ {print $2}'
}

down() {
	ip netns del "$NS" 2>/dev/null || true
	ip link del "$VETH_HOST" 2>/dev/null || true
	echo "Bench down."
}

case "$1" in
	up) up;;
	down) down ;;
	*)	echo "Usage: $0 up|down" ; exit 1 ;;
esac